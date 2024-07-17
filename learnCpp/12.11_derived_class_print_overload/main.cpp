#include <iostream>
#include <ostream>

/*
    - 다형성을 사용할 수 없는 경우: 출력 연산자
    - 간접적인 방법으로 출력 연산자를 변경해서 overload / override 할 수 있음
*/

class Base
{
public:
    Base() {}

    // member가 아니어서 직접 overriding 할 수 없어서 print()에 일을 다 시킴
    friend std::ostream& operator <<(std::ostream& out, const Base& base)
    {
        return base.print(out);
    }

    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Base";
        return out;
    }

};

class Derived : public Base
{
public:
    std::ostream& print(std::ostream& out) const override
    {
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b;
    Derived d;

    std::cout << b << std::endl;
    std::cout << d << std::endl;

    Base &bref = d;
    std::cout << bref << std::endl;
    return 0;
}