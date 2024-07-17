#include <iostream>

/*
    - virtual destructor: 부모 클래스 캐스팅을 가지고 한번에 자식 클래스의 동적 할당을 해제할 수 있어서 쓰기 편함
    - override:
*/


class Base
{
public:
    // delete Base를 하면, Base의 자식 소멸자들까지 다 호출
    virtual ~Base()
    {
        std::cout << "~Base()" << std::endl;
    }
};

class Derived : public Base
{
private:
    int* m_array;

public:
    Derived(const int& length)
    {
        m_array = new int[length];
    }

    // Base 소멸자에 virtual이 붙어야 override 사용 가능
    virtual ~Derived() override
    {
        std::cout << "~Derived()" << std::endl;
        delete[] m_array;
    }
};


int main()
{
    // stack에 객체 생성
    // Derived derived(5);

    // heap에 객체 생성, pointer = new "Instance"()이면 생성자, []이면 배열
    Derived* derived2 = new Derived(5);
    Base* base = derived2;
    delete base;

    return 0;
}