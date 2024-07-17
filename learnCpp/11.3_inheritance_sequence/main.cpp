#include <iostream>

/*
    - is-a relationship
    - 중복되는 기능이 있을 때, 수정하는 관점에서 한군데에서만 수정하면 돼서 객체지향 관점에서 용이
*/

class Mother
{
protected:
    int m_i;

public:
    // 기본값을 넣어줄 수 있음
    Mother(const int& i_in = 0)
        : m_i(i_in)
    {
        std::cout << "Mother constructor 2 : " << m_i << std::endl;
    }
};

class Child : public Mother
{
private:
    double m_d;
    // float m_d;
    // int m_temp;

public:
    Child()
        : m_d(123.0), Mother(4567) // , m_i(1) 이 안되는 이유가 생성자 호출 시에 먼저 Mother()을 호출하고 나서 Child()를 오기 때문
    {
        // Mother() 생성자 호출이 끝나고 난 뒤 대입연산자로 m_i를 바꿔줄 수는 있음 (m_i : public or protected 일 경우)
        // this->m_i = 10;
        // this->Mother::m_i = 1024;
        std::cout << "child constructor : " << m_d << std::endl;
    }
};

class A
{
private:

public:
    A(int a)
    {
        std::cout << "A constructor : " << a << std::endl;
    }

    ~A()
    {
        std::cout << "A destructor" << std::endl;
    }
};

class B : public A
{
private:

public:
    B(int a, double b)
        : A(a)
    {
        std::cout << "B constructor : " << b << std::endl;
    }

    ~B()
    {
        std::cout << "B destructor" << std::endl;
    }
};

class C : public B
{
private:

public:
    C(int a, double b, char c)
        : B(a, b)
    {
        std::cout << "C constructor : " << c << std::endl;
    }

    ~C()
    {
        std::cout << "C destructor" << std::endl;
    }
};


int main()
{
    /* 11.3 강의 내용 */
    // Child c1;

    // C c;
    // std::cout << std::endl;
    // B b;
    // std::cout << std::endl;

    /* 11.4 강의 내용 */
    // Child c1;

    // std::cout << sizeof(Mother) << std::endl;
    // // 가장 큰 멤버변수(double)의 크기에 따라 경계가 정해지면서 그보다 작은 데이터타입들(int)은 모두 패딩이 더해져서(int + 4 byte) 가장 큰 바이트 수 단위로 할당됨
    // std::cout << sizeof(Child) << std::endl;

    C c(123, 234.567, 'A');


    return 0;
}