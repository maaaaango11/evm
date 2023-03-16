#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;
#define N (1024) // размерность матрицы
#define M (3) // количество членов ряда (итераций)

void matrixSum (float* first, float* second, float* result) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i * N + j] = first[i * N + j] + second[i * N + j];
}

void matrixSub (float* first, float* second, float* result) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i * N + j] = first[i * N + j] - second[i * N + j];
}

void matrixMult(float* first, float* second, float* result) {
    float sum = 0;
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j)
                sum += first[i * N + k] * second[k * N + j];
}

float A_1(float* A) {
    float max = 0, tmp = 0;
    for (int i = 0; i < N; ++i) {
        tmp = 0;
        for (int j = 0; j < N; ++j)
            tmp += abs(A[i * N + j]);
        if (tmp > max) max = tmp;
    }
    return max;
}

float A_inf(float* A) {
    float max = 0, tmp = 0;
    for (int i = 0; i < N; ++i) {
        tmp = 0;
        for (int j = 0; j < N; ++j)
            tmp += abs(A[j * N + i]);
        if (tmp > max) max = tmp;
    }
    return max;
}

void IMatrixFill(float* I) {
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            I[i * N + j] = (i == j);
}
void matrixEmpty(float* A){
    for(int i = 0; i<N; ++i)
        for(int j = 0; j<N; ++j)
            A[i * N + j] = 0;
}

float* invertMatrix(float* A) {
    auto* B = (float*)calloc(N * N, sizeof(float)); // A^т / a_1 * a_inf
    auto* I = (float*)calloc(N * N, sizeof(float)); // единичная матрица
    auto* BA = (float*)calloc(N * N, sizeof(float)); // B * A
    auto* R = (float*)calloc(N * N, sizeof(float)); // I - BA
    auto* res = (float*)calloc(N * N, sizeof(float)); // result
    auto* buf = (float*)calloc(N * N, sizeof(float)); // buffer
    float a_1 = A_1(A);
    float a_inf = A_inf(A);
    IMatrixFill(I);
    IMatrixFill(buf);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            B[i * N + j] = A[j * N + i] / (a_inf * a_1);

    matrixEmpty(BA);
    matrixMult(A, B, BA);
    matrixSub(I, BA, R);
    for (int k = 0; k < M - 1; ++k) {
        matrixMult(I, R, BA);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                I[i * N + j] = BA[i * N + j];

        matrixSum(buf, I, buf);
    }
    matrixMult(buf, B, res);
    free(B);
    free(BA);
    free(I);
    free(R);
    free(buf);
    return res;
}

int main()
{
    auto* A = (float*)calloc(N * N, sizeof(float)); // original matrix
    float* Inv;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            A[i * N + j] = (i == j);
    Inv = invertMatrix(A);
/*
for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j)
        std::cout << Inv[i * N + j] << ' ';
    std::cout << std::endl;
}
*/
    free(A);
    free(Inv);
    return 0;
}