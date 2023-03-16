#include <iostream>
#include <cmath>
//#include <stdio.h>
//#include <stdlib.h>
#include <xmmintrin.h>
using namespace std;
#define N (2048) // размерность матрицы
#define M (10) // количество членов ряда (итераций)

void matrixSum(const float* first, const float* second, float* result) {
    __m128 sum;
    __m128* AA;
    __m128* BB;
    for (int i = 0; i < N; ++i) {
        AA = (__m128*)(first + i * N);
        BB = (__m128*)(second + i * N);
        for (int j = 0; j < N / 4; ++j) {
            sum = _mm_add_ps(AA[j], BB[j]);
            _mm_store_ps((result + i * N + j * 4), sum);
        }
    }
}

void matrixSub(const float* first, const float* second, float* result) {
    __m128 sub;
    __m128* AA;
    __m128* BB;
    for (int i = 0; i < N; ++i) {
        AA = (__m128*)(first + i * N);
        BB = (__m128*)(second + i * N);
        for (int j = 0; j < N / 4; ++j) {
            sub = _mm_sub_ps(AA[j], BB[j]);
            _mm_store_ps(result + i * N + j * 4, sub);
        }
    }
}

void matrixMult(const float* first, const float* second, float* result) {
    __m128 line, column, temp, sum;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k){
            for (int j = 0; j < N; j+=4) {
                column = _mm_set1_ps(first[i * N + k]);
                line = _mm_load_ps(second + k * N + j);
                temp = _mm_mul_ps(column, line);
                sum = _mm_load_ps(result + i*N +j);
                sum = _mm_add_ps(sum, temp);
                _mm_store_ps(result + i * N + j, sum);
            }
        }
    }
}

float A_1(float* A) {
    float max = 0, tmp = 0;
    for (int i = 0; i < N; ++i) {
        tmp = 0;
        for (int j = 0; j < N; ++j) {
            tmp += abs(A[i * N + j]);
        }
        if (tmp > max) max = tmp;
    }
    return max;
}

float A_inf(float* A) {
    float max = 0, tmp = 0;
    for (int i = 0; i < N; ++i) {
        tmp = 0;
        for (int j = 0; j < N; ++j) {
            tmp += abs(A[j * N + i]);
        }
        if (tmp > max) max = tmp;
    }
    return max;
}

void IMatrixFill(float* I) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            I[i * N + j] = (i == j);
        }
    }
}

float* invertMatrix(float* A) {
    auto* B = new float[N * N]; // A(т) / a_1 */ a_inf
    auto* I = new float[N * N]; // единичная матрица
    auto* BA = new float[N * N]; // B * A
    auto* R = new float[N * N]; // I - BA
    auto* buf = new float[N * N]; // buffer
    auto* res = new float[N * N]; // result -- его не удалять.
    float a_1 = A_1(A);
    float a_inf = A_inf(A);
    IMatrixFill(I);
    IMatrixFill(buf);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            B[i * N + j] = A[j * N + i] / (a_inf * a_1);
        }
    }

    matrixMult(A, B, BA);
    matrixSub(I, BA, R);
    for (int k = 0; k < M - 1; ++k) {
        matrixMult(I, R, BA);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                I[i * N + j] = BA[i * N + j];
            }
        }
        matrixSum(buf, I, buf);
    }
    matrixMult(buf, B, res);
    delete[](B);
    delete[](BA);
    delete[](I);
    delete[](R);
    delete[](buf);
    return res;
}

int main()
{
    auto* A = new float[N * N]; // original matrix
    float* Inv;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            A[i * N + j] = (i == j);
        }
    }
    Inv = invertMatrix(A);
/*
for (size_t i = 0; i < N; ++i) {
for (size_t j = 0; j < N; ++j) {
std::cout << Inv[i * N + j] << ' ';
}
std::cout << std::endl;
}
*/
    delete[](A);
    delete[](Inv);
    return 0;
}