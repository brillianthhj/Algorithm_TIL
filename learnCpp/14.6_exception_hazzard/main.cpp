#include <iostream>
#include <memory>

/*
    - 예외처리의 위험성과 단점
        - 메모리 처리가 안돼서 메모리릭이 발생할 수 있음 -> 스마트포인터로 해결!
        - for 문 안쪽에서 빈번하게 호출을 하는 코드를 throw-catch를 하는 것은 성능 상 안좋음
    - 모든 오류를 예외처리로 잡아내지 마라: 예측할 수 없는 이유 때문에 고장이 날 경우를 위해서 예외처리
*/

class A
{
public:
    ~A()
    {
        std::cout << "~A() occured" << std::endl;
        // 정상적 상황에서는 소멸자에서는 throw를 던지지 않음
        // throw "error";
    }
};


int main()
{
    try {
        // int* i = new int[1000000];
        // // 얘가 바운더리 밖으로 벗어나면 알아서 delete[] i;를 해줌
        // std::unique_ptr<int> up_i(i);

        // // do something with i
        // throw "error";

        // // delete[] i;

        A a;
    }
    catch (...)
    {
        std::cout << "Catch" << std::endl;
    }

    return 0;
}