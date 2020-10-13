#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <x86intrin.h>
#define A 10.

static const int64_t proc_tc = 1800000000;

void saxpy(int n)
{
    std::vector<int> X(n);
    std::vector<int> Y(n);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 1000);
    for (int i = 0; i < n; i++)
    {
        X[i] = distribution(generator);
        Y[i] = distribution(generator);
    }
    int64_t start = __rdtsc();
    for(int i = 0; i < n; i++)
        Y[i] = X[i] * A + Y[i];
    std::cout << "Time for " << n << " iterations: " << std::fixed << std::setprecision(10) << (double_t)(__rdtsc() - start) / proc_tc << std::endl;

}

int main()
{
    int n = 0;
    std::cin >> n;
    saxpy(n);
    return 0;
}
