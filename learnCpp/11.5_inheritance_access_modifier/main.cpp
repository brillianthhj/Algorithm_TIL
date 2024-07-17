#include <iostream>

/*
    - is-a relationship
    - 중복되는 기능이 있을 때, 수정하는 관점에서 한군데에서만 수정하면 돼서 객체지향 관점에서 용이
*/

class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

class Derived : private Base  // 외부에서 public 아닌 이상 접근 불가
{
public:
    Derived()
    {
        m_protected = 123;
        Base::m_public;
        Base::m_protected;
        Base::m_private;
    }
};

class GrandChild : public Derived
{
public:
    GrandChild()
    {
        Derived::m_public;
        Derived::m_protected;
        Derived::m_private;
    }
};

int main()
{
    Base base;

    base.m_public = 123;

    Derived derived;
    derived.m_public = 1024;
    derived.m_protected = 1025;
    derived.m_private = 1026;

    GrandChild gchild;
    gchild.m_public = 0;
    gchild.m_protected = 0;
    gchild.m_private = 0;

    return 0;
}