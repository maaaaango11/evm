blas
#include <iostream>
#include <cmath>
#include <unistd.h>
#ifdef __INTEL_COMPILER
#include <mkl_cblas.h>
#else
#include <cblas.h>
#endif
using namespace std;
#define N (2048) // размерность матрицы
#define M (10) // количество членов ряда (итераций)
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

float* invertMatrix(float* A) {
    auto* I = new float[N * N]; // единичная матрица
    auto* R = new float[N * N]; // I - BA
    auto* tmp1 = new float[N * N];
    auto* tmp2 = new float[N * N];
    auto* res = new float[N * N]; // result -- его не удалять.
    float a_1 = A_1(A);
    float a_inf = A_inf(A);
    IMatrixFill(I);
    IMatrixFill(res);
    IMatrixFill(tmp1);
    IMatrixFill(tmp2);
    cblas_sgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, -1.0 / (a_1 * a_inf), A, N, A, N, 1.0, R, N);
    for (int k = 0; k < M - 1; ++k) {
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, tmp1, N, R, N, 0.0, tmp2, N);
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1.0, I, N, tmp2, N, 0.0, tmp1, N);
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, I, N, tmp1, N, 1.0, res, N);
    }
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1.0, res, N, A, N, 0.0, res, N);
    delete[](tmp1);
    delete[](tmp2);
    delete[](I);
    delete[](R);
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