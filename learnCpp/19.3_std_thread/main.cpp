#include <iostream>
#include <string>
#include <thread>
#include <chrono>
// #include <vector>
#include <mutex>

std::mutex mtx; // mutual exclusion

int main()
{
    auto work_func = [](const std::string & name)
    {
        for (int i = 0; i < 5; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            mtx.lock();
            std::cout << name << " " << std::this_thread::get_id() << " is working " << i << std::endl;
            mtx.unlock();
        }
    };

    std::thread t1 = std::thread(work_func, "Hyejin");
    std::thread t2 = std::thread(work_func, "Zzang");

    t1.join();
    t2.join();


/** (2) full cpu threading
    const int num_pro = std::thread::hardware_concurrency();

    std::cout << "original: " << std::this_thread::get_id() << std::endl;

    std::vector<std::thread> my_threads;
    my_threads.resize(num_pro);

    for (auto & e : my_threads)
        e = std::thread([]() {
                        std::cout << std::this_thread::get_id() << std::endl;
                        while (true) {}
                        });

    for (auto & e : my_threads)
        e.join();

 */


/** (1) basic thread example
    // join()을 하지 않으면 새로운 스레드가 종료되기도 전에 main함수가 끝나는 현상이 있음.
    std::thread t1 = std::thread([]() {
        std::cout << "t1 thread: " <<  std::this_thread::get_id() << std::endl;
        while (true) {}});

    std::thread t2 = std::thread([]() {
        std::cout << "t2 thread: " <<  std::this_thread::get_id() << std::endl;
        while (true) {}});

    std::thread t3 = std::thread([]() {
        std::cout << "t3 thread: " <<  std::this_thread::get_id() << std::endl;
        while (true) {}});

    std::thread t4 = std::thread([]() {
        std::cout << "t4 thread: " <<  std::this_thread::get_id() << std::endl;
        while (true) {}});

    std::cout << "original: " << std::this_thread::get_id() << std::endl;

    // t1이 끝날때 까지 기다린다.
    t1.join();
    t2.join();
    t3.join();
    t4.join();
 */

    return 0;
}