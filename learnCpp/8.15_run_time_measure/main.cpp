#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
    void elapsed()
    {
        std::chrono::time_point<clock_t> end_time = clock_t::now();

        std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
    }
};

int main()
{
    std::random_device rnd_device;
    std::mt19937 mersenne_engine{ rnd_device() };

    std::vector<int> vec(100000);
    for (unsigned int i = 0; i < vec.size(); ++i)
        vec[i] = i;

    std::shuffle(std::begin(vec), std::end(vec), mersenne_engine);

    // for (auto &e : vec)
    //     std::cout << e << " ";
    // std::cout << std::endl;

    Timer timer;

    std::sort(std::begin(vec), std::end(vec));

    timer.elapsed();

    // for (auto &e : vec)
    //     std::cout << e << " ";
    // std::cout << std::endl;

    return 0;
}