#include <iostream>
#include <iomanip>
#include <random>
#include <sys/time.h>
#include <pthread.h>

int n_SIZE, threads_num;
std::vector<int> vector_x, res;
std::vector<std::vector<double>> matrix;

void * worker(void *arg)
{
    int tid, portion_size, row_start, row_end;

    tid = *(int *) arg;
    portion_size = n_SIZE / threads_num;
    row_start = tid * portion_size;
    row_end = (tid + 1) * portion_size;

    for (int i = row_start; i < row_end; i++){
        res[i] = 0;
        for (int j = 0; j < n_SIZE; j++){
            res[i] += matrix[i][j] * vector_x[j];
        }
    }
    return nullptr;
}

void * worker2(void *arg)
{
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution(1, 1000);
    int tid, portion_size, row_start, row_end;
    tid = *(int *) arg;
    portion_size = n_SIZE / threads_num;
    row_start = tid * portion_size;
    row_end = (tid + 1) * portion_size;

    for(int i = row_start; i < row_end; i++){
        vector_x[i] = distribution(generator);
        for(int j = 0; j < n_SIZE; j++){
            matrix[i][j] = distribution(generator);
        }
    }
    return nullptr;
}

int main(){
    struct timeval tstart = {}, tend = {};
    double exectime;
    double full_time;
    pthread_t *threads, *threads1;

    std::cout << "Enter vector size:" << std::endl;
    std::cin >> n_SIZE;
    std::cout << "Enter number of threads:" << std::endl;
    std::cin >> threads_num;

    vector_x.resize(n_SIZE), res.resize(n_SIZE);
    matrix.resize(n_SIZE, std::vector<double>(n_SIZE));

    //threads = (pthread_t *) malloc(threads_num * sizeof(pthread_t));
    //threads1 = (pthread_t *) malloc (threads_num * sizeof (pthread_t));
    threads = new pthread_t [threads_num];
    threads1 = new pthread_t [threads_num];


    gettimeofday(&tstart, nullptr);
    for (int i = 0; i < threads_num; i++){
        int *tid;
        tid = (int *) malloc(sizeof(int));
        *tid = i;
        pthread_create(&threads1[i], nullptr, worker2, (void *)tid);
    }
    for (int i = 0; i < threads_num; i++){
        pthread_join(threads1[i], nullptr);
    }
    gettimeofday(&tend, nullptr);
    exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0; // sec to ms
    exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms
    std::cout << "Number of threads: " << threads_num << " Random finished in: " << exectime / 1000.0 << std::endl;
    full_time = exectime / 1000.;
    exectime = 0, tend = {0}, tstart = {0};

    gettimeofday(&tstart, nullptr);
    for (int i = 0; i < threads_num; i++){
        int *tid;
        tid = (int *) malloc(sizeof(int));
        *tid = i;
        pthread_create(&threads[i], nullptr, worker, (void *)tid);
    }
    for (int i = 0; i < threads_num; i++){
        pthread_join(threads[i], nullptr);
    }
    gettimeofday(&tend, nullptr);

    exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0; // sec to ms
    exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms
    std::cout << "Number of threads: " << threads_num << " Vectors execution time: " << exectime / 1000.0 << std::endl;
    full_time += exectime / 1000.;
    std::cout << "Full program time on " << threads_num << " threads is: " << full_time << std::endl;
    return 0;
}

/* Results for 2000:
 * 1 - 44.1347
 * 2 - 2.7467
 * 3 - 2.03276
 * 4 - 13.252
 * 6 - 16.4053
 * 8 - 16.2685
*/