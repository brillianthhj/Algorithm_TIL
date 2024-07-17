#include <iostream>
#include <iterator>


class Something
{
public:

    // 간접적으로 static 변수를 생성자 단계에서 초기화 할 수 있음을 보여주는 예시..!
    // 원래는 외부에서 선언을 해서 초기화를 해야 함 or 생성자에서는 초기화 못했음
    class _init
    {
    public:
        _init()
        {
            s_value = 9876;
        }
    };

private:
    static int s_value;
    int m_value;

    // 간접적으로 static 변수를 생성자 단계에서 초기화 할 수 있음을 보여주는 예시..!
    static _init s_initializer;

public:
    Something()
        : m_value(123)// , s_value(1024) : static variable은 생성자에서 초기화 할 수 없음
    {}

    static int getValue()
    {
        // static function은 static member만을 쓸 수 있음
        return s_value;
    }

    int temp()
    {
        // non-static function은 내부적으로 instance를 가리키는 this->를 포함하며, non-static에서만 쓸 수 있음
        return this->s_value + this->m_value;
    }
};

//int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{
    std::cout << Something::getValue() << std::endl;

    Something s1, s2;
    std::cout << s1.getValue() << std::endl;
    //std::cout << s1.s_value << std::endl;

/*
    // member function의 pointer를 가져올 수 있음
    // function은 각 instance 별로 다른 주소값을 가지는 게 아니라, 메모리 한 공간에 있고,
    // 각 instance의 member variable을 가지고 같은 function을 사용하는 방식
    int (Something::*fptr1)() = &Something::temp;

    // instance 기반으로 함수가 구현돼야 하므로, s2가 꼭 필요
    std::cout << (s2.*fptr1)() << std::endl;
    std::cout << (s1.*fptr1)() << std::endl;

    // static function 은 instance "Something"을 포함하지 않아야 함수포인터를 만들 수 있음
    int (*fptr2)() = &Something::getValue;

    // 1) fptr2가 가리키는 주소에서 함수 getValue를 찾아 실행
    std::cout << fptr2() << std::endl;
    // 2) (*fptr2)를 통해 함수 getValue의 실제 주소에 접근하여 함수 실행
    std::cout << (*fptr2)() << std::endl;
*/



    return 0;
}