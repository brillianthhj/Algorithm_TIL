#include <iostream>

/*
    - 멤버 함수를 한 번 더 템플릿화 하기
    - 어떤 클래스가 이미 템플릿 화 되어 있는 경우에도 멤버 함수에 추가적인 템플릿을 적용할 수 있음
*/

template<typename T>
class A
{
private:
    T m_value;

public:
    A(const T& input)
        : m_value(input)
    {}

    template<typename TT>
    void doSomething(const TT& input)
    {
        std::cout << typeid(T).name() << " " << typeid(TT).name() << std::endl;
        std::cout << (TT)m_value << std::endl;
    }

    void print()
    {
        std::cout << m_value << std::endl;
    }
};

int main()
{
    A<int> a_int(123);
    // a_int.print();

    // // TT를 명시해주지 않으면, 알아서 자료형을 인식해줌
    // a_int.doSomething<float>(45.6f);
    // a_int.doSomething(45.6);
    // a_int.doSomething('a');

    A<char> a_char('A');
    a_char.print();

    // 문자 char 타입인데 65 로 출력함
    a_char.doSomething(1);
    a_char.doSomething<int>(5);

    return 0;
}