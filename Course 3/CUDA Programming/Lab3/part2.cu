#include <iostream>
#include <cmath>

#include <cuda_runtime.h>

__global__ void matrixInitByX(float *X) 
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    int l = blockDim.x * gridDim.x;
    X[i + j * l] = (float) (threadIdx.x + blockDim.y * blockIdx.x);
}

__global__ void matrixInitByY(float *X) 
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    int J = blockDim.x * gridDim.x;
    X[i + j * J] = (float) (threadIdx.y + blockDim.x * blockDim.y);
}

__global__ void transponse0(float *X, float *X_t)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    int N = blockDim.x * gridDim.x;

    X_t[j + i * N] = X[i + j * N];
}

int main(int argc, char* argv[])
{
    float *A_CUDA, *A_CUDA2, *A_CUDA_T;
    int n = 1 << 10;
    std::cout << n << std::endl;
    int numThreads = 32;
    int blockNum = n / numThreads;
    cudaMalloc((void **) &A_CUDA, n * n * sizeof(float));
    cudaMalloc((void **) &A_CUDA2, n * n * sizeof(float));
    cudaMallocManaged(&A_CUDA_T, n * n * sizeof(float));

    matrixInitByX<<<dim3(blockNum, blockNum), dim3(numThreads, numThreads)>>>(A_CUDA);
    cudaDeviceSynchronize();
    matrixInitByY<<<dim3(blockNum, blockNum), dim3(numThreads, numThreads)>>>(A_CUDA2);
    cudaDeviceSynchronize();
    transponse0<<<dim3(blockNum, blockNum), dim3(numThreads, numThreads)>>>(A_CUDA, A_CUDA_T);
    cudaDeviceSynchronize();
    
    cudaFree(A_CUDA);
    cudaFree(A_CUDA2);
    cudaFree(A_CUDA_T);
    return 0;
}