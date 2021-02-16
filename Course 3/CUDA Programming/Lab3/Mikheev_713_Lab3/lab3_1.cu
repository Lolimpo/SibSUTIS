#include <iostream>

__global__
void gInitVector(float *vec, int n)
{
    int i = threadIdx.x + blockDim.x * blockIdx.x;
    if(i < n)
        vec[i] = 1000.;
}

int main()
{
    float *A;
    int n;
    std::cin >> n;
    int blockSize = 128;
    int numBlocks = (n + blockSize - 1) / blockSize;
    A = new float [n];

    cudaMallocManaged(&A, n * sizeof(float));
    gInitVector<<<numBlocks, blockSize>>>(A, n);
    cudaDeviceSynchronize();
    cudaFree(A);

    return 0;
}