#include <iostream>

/*
    - friend 키워드는 특정 함수나 클래스가 다른 클래스의 비공개 멤버에 접근할 수 있도록 허용할 때 사용
    - 이는 캡슐화 원칙을 위반할 수도 있지만, 클래스 간의 밀접한 협력이나 특정 상황에서 유용할 수 있음
    - 연산자 오버로딩, 클래스 간의 접근, 테스트 목적 등 다양한 상황에서 사용됨
*/

class A;   // forward declaration

class B
{
private:
    int m_value = 2;

public:
    // A 클래스의 존재만 알아도 됨
    void doSomething(A& a);
};

class A
{
private:
    int m_value = 1;

    // // class B에 통째로 열어주지 않고, member function만 열어둠
    // friend class B;
    // friend member function, B안에 doSomething()을 알려줄 방법이 없음
    // 그래서 B class를 앞으로 보냄, B의 doSomething()의 존재가 명시된 상태
    friend void B::doSomething(A& a);

};

// void doSomething(A& a, B& b)
// {
//     std::cout << a.m_value << std::endl;
//     std::cout << b.m_value << std::endl;
// }

// B의 doSomething 함수를 직접 구현
void B::doSomething(A& a)
{
    std::cout << a.m_value << std::endl;
}

int main()
{
    A a;
    B b;
    // doSomething(a, b);
    b.doSomething(a);
    return 0;
}