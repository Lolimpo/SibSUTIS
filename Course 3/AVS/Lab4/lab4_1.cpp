#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <x86intrin.h>

static const int64_t proc_tc = 1800000000;

void dgemm_blas(int n)
{
    std::vector<std::vector<double_t>> first(n, std::vector<double_t>(n, 0));
    std::vector<std::vector<double_t>> second(n, std::vector<double_t>(n, 0));
    std::vector<std::vector<double_t>> multi(n, std::vector<double_t>(n, 0));
    std::default_random_engine generator;
    std::uniform_real_distribution<double_t > distribution(1, 100);
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            first[i][j] = distribution(generator);
            second[i][j] = distribution(generator);
        }
    }
    int64_t start = __rdtsc();
    for(auto & i: multi)
    {
        for(int j = 0; j < i.size(); j++)
        {
            for(int k = 0; k < n; k++)
                i[j] += first[j][k] * second[k][j];
        }
    }
    std::cout << "Time for " << n << " iterations: " << std::fixed << std::setprecision(10)
        << (double_t)(__rdtsc() - start) / proc_tc << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    dgemm_blas(n);
    return 0;
}
