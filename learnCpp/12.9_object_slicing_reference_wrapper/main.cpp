#include <iostream>
#include <vector>
#include <functional>

/*
    - 상속에서, 자식 클래스가 부모 클래스보다 더 많은 정보를 가지고 있음
    - 객체 잘림(object slicing): 작은 부모 객체에 강제로 큰 자식 클래스 객체를 대입하는 경우,
     부모에게 없는 자식 클래스의 멤버 변수, 함수가 사라질 수 있음
    - Reference wrapper : 객체 잘림 현상을 방지
*/

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        std::cout << "I'm Base" << std::endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        std::cout << "I'm derived" << std::endl;
    }
};

void doSomething(Base& b)
// 다형성 사라짐
// void doSomething(Base b)
{
    b.print();
}

int main()
{
    // Derived d;
    // // Base& b = d;

    // // d의 object slining, 다형성 사라짐
    // Base b = d;
    // b.print();

    // doSomething(d);

    Base b;
    Derived d;

    // vector에 레퍼런스를 넣을 수 없음 (Base&)
    std::vector<Base*> my_vec;
    my_vec.push_back(&b);
    my_vec.push_back(&d);

    for (auto& ele : my_vec)
        ele->print();

    // vector에 레퍼런스 사용하는 법
    std::vector<std::reference_wrapper<Base>> my_vec2;
    my_vec2.push_back(b);
    my_vec2.push_back(d);

    for (auto& ele: my_vec2)
        ele.get().print();

    return 0;
}