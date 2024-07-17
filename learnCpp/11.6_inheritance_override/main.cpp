#include <iostream>
#include <ostream>

/*
    - is-a relationship
    - 중복되는 기능이 있을 때, 수정하는 관점에서 한군데에서만 수정하면 돼서 객체지향 관점에서 용이
*/

class Base
{
protected:
    int m_i;

public:
    Base(const int& value)
        : m_i(value)
    {}

    void print()
    {
        std::cout << "I'm base " << std::endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Base& base)
    {
        out << "base : " << base.m_i;
        return out;
    }
};

class Derived : public Base
{
private:
    double m_d;

public:
    Derived(const int& value)
        : Base(value), m_d(value - 1)
    {}

    // void print()
    // {
    //     Base::print();
    //     std::cout << "I'm derived" << std::endl;
    // }

    friend std::ostream& operator << (std::ostream& out, const Derived& derived)
    {
        // Base::operator << () 호출, derived는 base 내용을 메모리 내 앞부분 주소값에 가지고 있다!
        std::cout << static_cast<Base>(derived) << std::endl;
        out << "derived : " << derived.m_i << " " << derived.m_d;
        return out;
    }

    // Derived 객체로 접근했을 때 public으로 쓸 수 있다!
    using Base::m_i;

private:
    // Base::print, Derived에서 못쓰게 막는 법
    using Base::print;  // do not add ()
    void print() = delete;
};

int main()
{
    Base base(5);
    base.print();

    Derived derived(8);
    //derived.print();

    std::cout << base << std::endl;
    std::cout << derived << std::endl;

    // Derived 객체로 접근했을 때 public으로 쓸 수 있다!
    derived.m_i = 1024;

    return 0;
}