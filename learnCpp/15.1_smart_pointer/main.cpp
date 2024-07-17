#include <ios>
#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

/*
    - smart pointer and move semantics
    - value semantics (copy semantics)
    - reference semantics (pointer)
    - move semantics (move)
*/

// RAII : resource acquisition is initialization
// 호출한 곳에서 delete를 선언

void doSomething()
{
    try
    {
        // Resource* res = new Resource;   // dull pointer: delete를 끝까지 책임 안지는 포인터
        // 자체가 스마트 포인터라서 * 표시 필요가 없음
        AutoPtr<Resource> res = new Resource;

        return;

        // work with res
        if (true)
        {
            // // 전통적 강의에서는 꼭 당부, 최근에는 smart pointer로 신경 안씀
            // delete res;
            // return;
            throw -1;   // delete를 할 수 없는 난감한 문제..!
        }

        // delete res;

    }
    catch (...)
    {

    }

    return;
}
int main()
{
    doSomething();

    AutoPtr<Resource> res1(new Resource);   // int i; int* ptr1(&i); int* ptr2 = nullptr;
    AutoPtr<Resource> res2;

    std::cout << std::boolalpha;

    std::cout << res1.m_ptr << std::endl;
    std::cout << res2.m_ptr << std::endl;

    // res2 = res1; // move semantics
    res2 = std::move(res1);

    std::cout << res1.m_ptr << std::endl;
    std::cout << res2.m_ptr << std::endl;



    return 0;
}