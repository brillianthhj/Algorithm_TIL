#include <iostream>
#include <string>

// class Simple
// {
// private:
//     int m_id;

// public:
//     Simple(const int& id)
//     {
//         // 모든 멤버함수, 멤버변수에 this-> 가 생략되어 있음
//         this->setID(id);
//         // this->m_id;

//         std::cout << this << std::endl;
//     }

//     void setID(const int& id) { m_id = id; }
//     int  getID() { return m_id; }
// };

class Calc
{
private:
    int m_value;

public:
    Calc(const int& init_value)
        : m_value(init_value)
    {}

    Calc& add(const int& value) { m_value += value; return *this; }
    Calc& sub(const int& value) { m_value -= value; return *this; }
    Calc& mult(const int& value) { m_value *= value; return *this; }

    void print()
    {
        std::cout << m_value << std::endl;
    }
};

int main()
{
    // Simple s1(1), s2(2);
    // s1.setID(2);
    // s2.setID(4);

    // std::cout << &s1 << " " << &s2 << std::endl;

    // // 내부에서 Simple::setID(&s2, 4) == s2.setID(4);

/*
    // cal을 여러번 치기 번거롭다
    Calc cal(10);
    cal.add(10);
    cal.sub(1);
    cal.mult(2);

    cal.print();
*/

    // this를 통해서 자기자신 리턴 : chanining member function
    Calc cal(10);
    // cal.add(10).sub(1).mult(2);
    // cal.print();
    Calc(10).add(10).sub(1).mult(2).print();

    Calc &temp1 = cal.add(10);
    Calc &temp2 = temp1.sub(1);
    Calc &temp3 = temp2.mult(2);
    temp3.print();

    return 0;
}