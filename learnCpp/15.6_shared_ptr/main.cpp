#include <iostream>
#include <memory>
#include "Resource.h"

/*
   - std::shared_ptr : 소유권을 여러 군데에서 공유할 수 있음
   - shared ptr이 몇개인지 세는 데이터를 가지고 있음
   - 직접적인 res을 각각 다른 곳으로 호출시키면 몇 개인지 셀 수가 없으니 shared_ptr객체들끼리 할당시켜야 함
*/

void soSomething(std::unique_ptr<Resource> res)
{

}

int main()
{
    {
        // 간접적 방식 : 선호 X
        Resource* res = new Resource(3);
        res->setAll(1);
        std::shared_ptr<Resource> ptr1(res);

        // X : 파라메터에 간접 할당
        soSomething(std::unique_ptr<Resource>(new Resource(1000000)));

        // 직접적 방식 : 선호 O
        // auto ptr1 = std::make_shared<Resource>(3);
        // ptr1->setAll(1);

        // O : 파라메터에 직접 할당
        soSomething(std::make_unique<Resource>(1000000));

        ptr1->print();

        {
            // ptr1은 외부에 있고, 나머지 ptr2, ptr4는 여기 있어서 블록을 벗어나면 알아서 객체는 사라지지만,
            // ptr1이 값을 들고 있음
            std::shared_ptr<Resource> ptr2(ptr1);
            auto ptr4 = ptr1;

            // ptr1이 아니라 res를 직접 지워버리면, shared_ptr 이 공유되는 ptr을 확인할 방법이 없다..!
            // std::shared_ptr<Resource> ptr3(res);

            ptr2->setAll(3);
            ptr2->print();

            std::cout << "Going out of the block" << std::endl;
        }

        ptr1->print();

        std::cout << "Going out of the outer block" << std::endl;
    }

    return 0;
}