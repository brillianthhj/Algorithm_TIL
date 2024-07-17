#include <iostream>
#include <memory>
#include <utility>
#include "Resource.h"

/*
   - std::unique_ptr : 포인터가 가리키고 있는 데이터의 소유권이 한 곳에만 속할 경우에 사용하는 스마트 포인터
*/

auto doSomething()
{
    // auto res1 = std::make_unique<Resource>(5);
    // return res1;

    return std::unique_ptr<Resource>(new Resource(5));

    // return std::make_unique<Resource>(5);
}

// &연산자를 빼면, l-value를 넣으면서 복사생성자가 호출되는데, unique 하니까 컴파일이 안됨
// 혹은 &연산자를 빼고, 호출할 때 r-value 를 집어넣으면 가능하지만, 그럼 호출하는 곳에서 값을 nullptr로 뺏겨서 다음 진행이 안됨
// void doSomething2(std::unique_ptr<Resource>& res)
void doSomething2(Resource* res)
{
    res->setAll(10);
}


int main()
{
    // {
    //     // Resource* res = new Resource(10000000);

    //     std::unique_ptr<Resource> res(new Resource(10000000));

    //     // early return or throw

    //     // delete res;
    // }

    // {
    //     std::unique_ptr<int> upi(new int);

    //     // auto* ptr = new Resource(5);
    //     // std::unique_ptr<Resource> res1(ptr);

    //     // 권장하는 방법
    //     // auto res1 = std::make_unique<Resource>(5);
    //     auto res1 = doSomething();

    //     res1->setAll(5);
    //     res1->print();

    //     std::unique_ptr<Resource> res2;

    //     // nullptr인지 아닌지 확인하기 위해 출력
    //     std::cout << std::boolalpha;
    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;

    //     // res2 = res1; // unique_ptr: 복사가 안됨, 소유권이 한곳에만 있어야 함
    //     res2 = std::move(res1);

    //     std::cout << std::boolalpha;
    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;

    //     if (res1 != nullptr) res1->print();
    //     if (res2 != nullptr) res2->print();     // (*res2).print();
    // }

    // {
    //     auto res1 = std::make_unique<Resource>(5);
    //     res1->setAll(1);
    //     res1->print();

    //     // unique_ptr을 parameter로 집어넣는 경우
    //     // doSomething2(std::move(res1));  // res1 기능 상실
    //     // doSomething2(res1);
    //     doSomething2(res1.get());   // unique_ptr 자체가 가지고 있는 포인터 호출 함수 get()

    //     res1->print();
    // }

    {
        // 하면 안되는 예제들
        Resource* res = new Resource;
        std::unique_ptr<Resource> res1(res);
        // X : unique_ptr 중복 사용
        std::unique_ptr<Resource> res2(res);


        // X : delete 쓰면 안됨
        delete res;
    }

    return 0;
}