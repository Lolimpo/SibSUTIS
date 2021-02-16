#include <iostream>
#include <cmath>

#include <cuda_runtime.h>

#define CUDA_CHECK_RETURN(value) {\
cudaError_t _m_cudaStat = value;\
if (_m_cudaStat != cudaSuccess) {\
 fprintf(stderr, "Error %s at line %d in file %s\n",\
 cudaGetErrorString(_m_cudaStat), __LINE__, __FILE__);\
 exit(1);\
} }


__global__
void compute(float X[], float Y[])
{
    X[threadIdx.x+blockDim.x*blockIdx.x] += Y[threadIdx.x+blockDim.x*blockIdx.x];
}

__global__
void matrix_init(float* X)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    int N = blockDim.x * gridDim.x;

    X[i + j * N] = float(i + j * N);
}

__global__
void transponse0(float* X, float *X_t)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    int N = blockDim.x * gridDim.x;

    X_t[j + i * N] = X[i + j * N];
}

int main(int argc, char *argv[])
{
    float *X, *Y, *Z, *CUDA_X, *CUDA_Y;
    for(int n = pow(2, 28), i = 0; i < 19; n /= 2, i++)
    {
    //int n = pow(2, 10);
        cudaEvent_t start, stop;
        cudaEventCreate(&start);
        cudaEventCreate(&stop);
        float milliseconds = 0.0;
        int thNum = std::stoi(argv[1]);
        int blNum = n / thNum;

        X = new float[n];
        Y = new float[n];
        Z = new float[n];
        for(int j = 0; j < n; j++)
        {
            X[j] = (float) rand () / RAND_MAX;
            Y[j] = (float) rand () / RAND_MAX;
        }
        CUDA_CHECK_RETURN(cudaMalloc((void**) &CUDA_X, n * sizeof (float)));
        CUDA_CHECK_RETURN(cudaMalloc((void**) &CUDA_Y, n * sizeof (float)));
        CUDA_CHECK_RETURN(cudaMemcpy(CUDA_X, X, n * sizeof (float), cudaMemcpyHostToDevice));
        CUDA_CHECK_RETURN(cudaMemcpy(CUDA_Y, Y, n * sizeof (float), cudaMemcpyHostToDevice));
        
        cudaEventRecord (start);
        compute<<<dim3(blNum), dim3(thNum)>>> (CUDA_X, CUDA_Y);
        CUDA_CHECK_RETURN(cudaDeviceSynchronize());

        cudaEventRecord (stop);
        CUDA_CHECK_RETURN(cudaMemcpy (Z, CUDA_X, n * sizeof (float), cudaMemcpyDeviceToHost));
        cudaEventSynchronize (stop);
        cudaEventElapsedTime (&milliseconds, start, stop);
        std::cout << milliseconds << std::endl;

        for (int j = 0; j < n; j++)
        {
            if (Z[j] != X[j] + Y[j])
            {
                std::cout << "Some big mess happened :c" << std::endl;
                return 0;
            }
        }
        cudaFree(CUDA_X);
        cudaFree(CUDA_Y);
        delete[] X;
        delete[] Y;
        delete[] Z;
    }
    return 0;
}
