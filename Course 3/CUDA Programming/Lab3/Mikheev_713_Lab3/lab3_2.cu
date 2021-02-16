#include <iostream>
#include <cmath>

#include <cuda_runtime.h>

__global__
void matrix_init(float* X)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    int N = blockDim.x * gridDim.x;

    X[i + j * N] = float(i + j * N);
}

__global__
void matrix_init2(float *X)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int N = blockDim.x * gridDim.x;

    X[i] = float(i * N);
}
__global__
void transponse0(float* X, float *X_t)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    int N = blockDim.x * gridDim.x;

    X_t[j + i * N] = X[i + j * N];
}

int main(int argc, char* argv[])
{
    float *A, *A_CUDA, *A_CUDA_T;
    int n = 2048;
    int numThreads = 32;
    int blockNum = n / numThreads;
    A = new float[n * n];
    A_CUDA = new float[n * n];
    A_CUDA_T = new float[n * n];

    cudaMallocManaged(&A, n * n * sizeof(float));
    cudaMallocManaged(&A_CUDA, n * n * sizeof(float));
    cudaMallocManaged(&A_CUDA_T, n * n * sizeof(float));

    matrix_init<<<dim3(blockNum, blockNum), dim3(numThreads, numThreads)>>>(A_CUDA);
    cudaDeviceSynchronize();
    matrix_init2<<<blockNum * blockNum, numThreads * numThreads>>>(A_CUDA);
    cudaDeviceSynchronize();
    transponse0<<<dim3(blockNum, blockNum), dim3(numThreads, numThreads)>>>(A_CUDA, A_CUDA_T);
    cudaDeviceSynchronize();
    
    cudaFree(A_CUDA_T);
    cudaFree(A_CUDA);
    cudaFree(A);
    return 0;
}
