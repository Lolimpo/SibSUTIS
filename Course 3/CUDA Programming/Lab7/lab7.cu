#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>

struct func
{
	float u, t, h;
	func(float _u, float _t, float _h) :
		u(_u), t(_t), h(_h) {};

	__host__ __device__
		float operator() (const float &x, const float &y) const 
		{
			return x + (y - x) * u * t / h;
		}
};

__global__ void funcCUDA(float *x, float *y, float u, float t, float h)
{
	int offset = threadIdx.x + blockDim.x * blockIdx.x;
	y[offset + 1] = x[offset + 1] + (x[offset] - x[offset + 1]) * u * t / h;
}

int main()
{
	float elapsedTime;
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	cudaEventRecord(start, 0);
	thrust::host_vector<float> A_host(1 << 10);
	for (int i = 0; i < A_host.size(); ++i)
		A_host[i] = exp(-powf((i / 100.0 - 4.5), 2)) * 100 /  (2 * sqrtf(2 * M_PI));
	thrust::device_vector<float> A(1 << 10);
	thrust::copy(A_host.begin(), A_host.end(), A.begin());
	for (int i = 0; i < 1000; ++i)
		thrust::transform(A.begin() + 1, A.end(), A.begin(), A.begin(), func(1.1, 0.9, 1.4));
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&elapsedTime, start, stop);
	printf("%f\n", elapsedTime);

	cudaEventRecord(start, 0);
	float *vect, *vectRes, *vect_GPU, *vectRes_GPU;
	vect = (float*)malloc((1 << 10) * sizeof(float));
	vectRes = (float*)malloc((1 << 10) * sizeof(float));
	cudaMalloc((void**)&vect_GPU, ((1 << 10) + 1) * sizeof(float));
	cudaMalloc((void**)&vectRes_GPU, ((1 << 10) + 1) * sizeof(float));
	for (int i = 0; i < (1 << 10); ++i)
		vect[i] = exp(-powf((i / 100.0 - 4.5), 2)) * 100 / (2 * sqrtf(2 * M_PI));
	cudaMemcpy(vect_GPU, vect, (1 << 10) * sizeof(float), cudaMemcpyHostToDevice);
	for (int i = 0; i < 1000; ++i) 
	{
		funcCUDA << <4, 256 >> > (vect_GPU, vectRes_GPU, 1.1, 0.9, 1.4);
		cudaMemcpy(vect_GPU, vectRes_GPU + 1, (1 << 10) * sizeof(float), cudaMemcpyDeviceToDevice);
	}
	cudaMemcpy(vectRes, vectRes_GPU + 1, (1 << 10) * sizeof(float), cudaMemcpyDeviceToHost);
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&elapsedTime, start, stop);
	printf("%f\n", elapsedTime);
}

