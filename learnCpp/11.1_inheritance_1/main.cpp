#include <iostream>

/*
    - is-a relationship
*/

// 일반화 된 요소를 Mother class로 사용
class Mother
{
private:
    int m_i;

public:
    Mother(const int& i_in)
        : m_i(i_in)
    {
        std::cout << "Mother constructor" << std::endl;
    }

    void setValue(const int& i_in)
    {
        m_i = i_in;
    }

    int getValue()
    {
        return m_i;
    }
};

// Mother class의 기능을 기본적으로 다 사용 가능
// derived class
class Child : public Mother
{
private:
    double m_d;

public:
    Child(const int& i_in, const double& d_in)
        // : m_i(i_in), m_d(d_in) // Mother::m_i를 할당하기 까다로움
        // 2) 초기화리스트에서 (안만들어져 있는) Mother 기본 생성자 호출하면 OK
        : Mother(i_in), m_d(d_in)
    {
        // Child constructor 호출하면서 상속 신경써야 하기 때문에, 기존에 Mother constructor가 재정의 안됐을 때의 default constructor를 호출해서 잘 쓰고 있었는데
        // Mother(const int& i_in)인 변형된 constructor가 생기니까 오류를 뿜는 상황임
        // 1) Mother() : m_i(0) {} 이런식으로 기본 생성자 만들어놓으면 OK
        // Mother::setValue(i_in);
        // m_d = d_in;
    }

    void setValue(const int& i_in, const double& d_in)
    {
        Mother::setValue(i_in);
        m_d = d_in;
    }

    void setValue(const double& d_in)
    {
        m_d = d_in;
    }

    double getValue()
    {
        return m_d;
    }
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
    Mother mother(1024);
    // mother.setValue(1024);
    std::cout << mother.getValue() << std::endl;
    std::cout << &mother << std::endl;

    Child child(1025, 128);
    // child에서 mother의 setValue 호출이 가능함
    // child.Mother::setValue(1024);
    // child.setValue(128);
    std::cout << child.Mother::getValue() << std::endl;
    std::cout << child.getValue() << std::endl;
    std::cout << &child << std::endl;

    Mother* motherPartOfChild = &child;
    std::cout << motherPartOfChild << std::endl;

    return 0;
}