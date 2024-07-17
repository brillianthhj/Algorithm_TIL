#include <iostream>
#include <future>   // async, future, promise
#include <thread>


int main()
{
    // //multi-threading
    // {
    //     // 스코프를 넓게 잡고, 일반 변수를 쓰레드들이 공유하는 것이 일반적
    //     int result;
    //     std::thread t([&] {result = 1 + 2;});
    //     t.join();
    //     std::cout << result << std::endl;
    // }

    // // task-based parallelism
    // {
    //     // std::future<int> fut = ...
    //     // async: 메인 스레드가 이뤄지는 것과 무관하게 비동기적으로 동작하도록, 무거운 작업을 fut가 한번에 받음
    //     // async가 작업을 마칠 때까지 미래를 기다려 준다는 개념
    //     auto fut = std::async([] {return 1 + 2; });
    //     std::cout << fut.get() << std::endl;
    // }

/*
    // future and promise
    {
        std::promise<int> prom;
        auto fut = prom.get_future();

        auto t = std::thread(
            [](std::promise<int>&& prom)
            {
                prom.set_value(1 + 2);
            },
            std::move(prom)
        );

        std::cout << fut.get() << std::endl;
        t.join();
    }
*/

    {
        auto f1 = std::async([] {
            std::cout << "async1 start" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "async1 end" << std::endl;
        });

        auto f2 = std::async([] {
            std::cout << "async2 start" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "async2 end" << std::endl;
        });

        std::cout << "Main function" << std::endl;
    }

    return 0;
}