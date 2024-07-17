#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <atomic>
#include <future>
#include <numeric>      // std::inner_product
#include <execution>    // parallel execution
#include <vector>

std::mutex mtx;

void dotProductNaive(const std::vector<int>& v0, const std::vector<int>& v1,
    const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
    for (unsigned i = i_start; i < i_end; ++i)
        sum += v0[i] * v1[i];
}

void dotProductLock(const std::vector<int>& v0, const std::vector<int>& v1,
    const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
    // std::cout << "Thread start " << std::endl;

    for (unsigned i = i_start; i < i_end; ++i)
    {
        // 락이 걸리는 곳이 너무 많이 실행이 되면 오히려 느려짐
        std::lock_guard<std::mutex> lock(mtx);

        sum += v0[i] * v1[i];
    }

    // std::cout << "Thread end " << std::endl;
}

void dotProductAtomic(const std::vector<int>& v0, const std::vector<int>& v1,
    const unsigned i_start, const unsigned i_end, std::atomic<unsigned long long> &sum)
{
    for (unsigned i = i_start; i < i_end; ++i)
    {
        // sum이 atomic인데, 원래 atomic이 integer 연산보다 느리기 때문에 빈번하게 동작하는 연산에서는 이점이 없음
        sum += v0[i] * v1[i];
    }
}

auto dotProductFuture(const std::vector<int>& v0, const std::vector<int>& v1,
    const unsigned i_start, const unsigned i_end)
{
    int sum = 0;    // local sum
    for (unsigned i = i_start; i < i_end; ++i)
        sum += v0[i] * v1[i];

    return sum;
}

int main()
{
/*
    v0 = {1, 2, 3}
    v1 = {4, 5, 6}
    v0 * v1 = 1 * 4 + 2 * 5 + 3 * 6
*/

    const long long n_data = 100'000'000;
    const unsigned  n_threads = 4;

    //initialize vectors
    std::vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);

    std::random_device seed;
    std::mt19937 engine(seed());

    std::uniform_int_distribution<> uniformDist(1, 10);

    for (long long i = 0; i < n_data; ++i)
    {
        v0.push_back(uniformDist(engine));
        v1.push_back(uniformDist(engine));
    }

    // ground truth
    std::cout << "std::inner_product" << std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();

        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

        std::cout << dur.count() << std::endl;
        std::cout << sum << std::endl;
        std::cout << std::endl;
    }

///*
    std::cout << "Naive" << std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();

        unsigned long long sum = 0;

        std::vector<std::thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

        std::cout << dur.count() << std::endl;
        std::cout << sum << std::endl;
        std::cout << std::endl;
    }
//*/

/*
    std::cout << "Lockguard" << std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();

        unsigned long long sum = 0;

        std::vector<std::thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

        std::cout << dur.count() << std::endl;
        std::cout << sum << std::endl;
        std::cout << std::endl;
    }
*/

/*
    std::cout << "Atomic" << std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();

        std::atomic<unsigned long long> sum(0);

        std::vector<std::thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

        std::cout << dur.count() << std::endl;
        std::cout << sum << std::endl;
        std::cout << std::endl;
    }
*/

    std::cout << "Future" << std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();

        unsigned long long sum(0);

        std::vector<std::future<int>> futures;
        futures.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;   // assumes remainder = 0
        for (unsigned t = 0; t < n_threads; ++t)
            futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread);

        for (unsigned t = 0; t < n_threads; ++t)
            sum += futures[t].get();

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

        std::cout << dur.count() << std::endl;
        std::cout << sum << std::endl;
        std::cout << std::endl;
    }

    // std::cout << "std::transform_reduce" << std::endl;
    // {
    //     const auto sta = std::chrono::steady_clock::now();

    //     // dot product 병렬처리 함수 = transform_reduce(), std::execution::par는 C++17 이후부터 가능
    //     // const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), )
    //     const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

    //     const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

    //     std::cout << dur.count() << std::endl;
    //     std::cout << sum << std::endl;
    //     std::cout << std::endl;
    // }

    // TODO: use divide and conquer strategy for std::thread
    // TODO: use promise

    return 0;
}