#include <iostream>

/*
    - 클래스의 생성법(이니셜라이제이션 리스트)에서 발생하는 예외 처리할 때 사용하는 function try문법
*/

class A
{
private:
    int m_x;

public:
    A(const int& x) : m_x(x)
    {
        if (x <= 0)
            throw 1;
    }
};

class B : public A
{
public:
    // B(const int& x) : A(x)
    // {}

    // 생성자에서 직접 try를 하고, { // do initialization } 안 까지 모두 점검 후 catch로 던져줌
    B(const int& x) try : A(x)
    {
        // do initialization
    }
    catch (...)
    {
        std::cout << "Catch in B constructor" << std::endl;
        // main()에 한번 더 catch로 잡으라고
        // throw;   // function try를 사용했을 때는 throw가 없지만 있는 것처럼 행동
    }


};

void doSomething()
{
    try
    {
        throw -1;
    }
    catch (...)
    {
        std::cout << "Catch in doSomething()" << std::endl;
    }
}

int main()
{
    try
    {
        // doSomething();
        B b(0);
    }
    catch (...)
    {
        std::cout << "Catch in main()" << std::endl;
    }

    return 0;
}