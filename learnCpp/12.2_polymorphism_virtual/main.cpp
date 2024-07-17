#include <iostream>

/*
    - 다형성의 목적은, 자식 클래스 함수들을 하나의 부모 클래스 포인터로 형변환해서 그 포인터로 자식 개체들을 모두 관리하려고 쓰는 것임
    - virtual은 타고타고 찾아가는 루트가 많아서, 빈번한 for문 안에 virtual 함수 넣으면 현저하게 느려짐
*/


class A
{
public:
    // 상위 함수가 virtual이 되면, 상속받은 함수들도 모두 virtual로 행동을 한다.
    virtual void print() { std::cout << "A" << std::endl; }
};

class B : public A
{
public:
    // 디버깅 용도로 virtual 을 명시해 주는 것이 좋다.
    virtual void print() {std::cout << "B" << std::endl; }
};

class C : public B
{
public:
    // 디버깅 용도로 virtual 을 명시해 주는 것이 좋다.
    virtual void print() {std::cout << "C" << std::endl; }
};

class D : public C
{
public:
    // 디버깅 용도로 virtual 을 명시해 주는 것이 좋다.
    virtual void print() {std::cout << "D" << std::endl; }
    // 리턴타입도 같아야 한다.
    // virtual int print() {std::cout << "D" << std::endl; return 0; }
};

int main()
{
    A a;
    // a.print();

    B b;
    // b.print();

    C c;
    // c.print();

    D d;
    // d.print();

    B &ref = c;
    ref.print();

    return 0;
}