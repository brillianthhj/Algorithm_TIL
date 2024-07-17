#include <iostream>
#include <ostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

std::mutex mtx; // mutual exclusion


int main()
{
    // std::atomic<int> shared_memory(0);
    int shared_memory(0);

    /**

     * shared_memory 접근 방식
     * 1) shared_memory -> CPU로 가져옴, 2) CPU 연산 (더하기), 3) 값을 다시 덮어씀
     * t1이 2)를 하고 있을 때, t2가 3)을 해버리면, 더하기 하나가 모자름
     * => 3단계를 한꺼번에 == atomic<int>
     */
    auto count_func = [&]() {
        for (int i = 0; i < 1000; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            // mtx.lock();

            std::lock_guard<std::mutex> lock(mtx); // mtx.unlock() 안될 경우 방지
            //std::scoped_lock lock(mtx); // C++17에 나온 진보된 lock!
            shared_memory++;    // atomic<int> 에서도 연산자 오버로딩 돼있음

            // mtx.unlock();
            // shared_memory.fetch_add(1); // 단점: atomic<int> 가 int 보다 오버헤드가 있음
        }
    };

    std::thread t1 = std::thread(count_func);
    std::thread t2 = std::thread(count_func);

    t1.join();
    t2.join();

    std::cout << "After" << std::endl;
    std::cout << shared_memory << std::endl;

    return 0;
}