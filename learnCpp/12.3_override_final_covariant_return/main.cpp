#include <iostream>
#include <typeinfo>

/*
    - override: 디버깅 용으로 부모 클래스 함수와 같은 파라메터, const 조건을 따르는 지 미연에 명시
    - final: 하위 상속 클래스들이 override를 못하게 막아놓음
*/


class A
{
public:
    // virtual void print() { std::cout << "A" << std::endl; }
    void print() { std::cout << "A" << std::endl; }
    virtual A* getThis() {
        std::cout << "A::getThis()" << std::endl;
        return this; }
};

class B : public A
{
public:
    // parameter가 다르면 overriding을 할 수가 없다.
    // override 를 명시해놓으면, 부모 클래스 함수랑 같은 파라메터, const, 리턴값을 가지는 지 미리 컴파일 에러 확인 가능
    // void print(int x) const override {std::cout << "B" << std::endl; }
    // void print(int x) override {std::cout << "B" << std::endl; }

    // final은 하위 상속받는 함수들이 override를 못하게 막음
    // void print() final {std::cout << "B" << std::endl; }
    void print() { std::cout << "B" << std::endl; }
    virtual B* getThis() {
        std::cout << "B::getThis()" << std::endl;
        return this; }
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

    // A &ref = b;
    // ref.print();

    A &ref = b;
    b.getThis()->print();
    ref.getThis()->print();

    std::cout << typeid(b.getThis()).name() << std::endl;
    std::cout << typeid(ref.getThis()).name() << std::endl;

    return 0;
}