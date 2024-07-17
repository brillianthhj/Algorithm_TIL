#include <algorithm>
#include <chrono>
#include <iostream>

class Fraction
{
public:
    int m_numerator;
    int m_denominator;

public:
    Fraction() {};

    Fraction(const int& num_in, const int& den_in = 1)
    {
        m_numerator = num_in;
        m_denominator = den_in;

        std::cout << "Fraction() constructor" <<  std::endl;
    };

    void print()
    {
        std::cout << m_numerator << " / " << m_denominator << std::endl;
    }
};

class Second
{
public:
    Second()
    {
        std::cout << "class second constructior()" << std::endl;
    }
};

class First
{
    Second sec;

public:
    First()
    {
        std::cout << "class First constructor()" << std::endl;
    }

};


int main()
{

/*
    // Fraction one_thirds(1, 3);
    // one_thirds.print();

    // 생성자가 하나라도 만들어지면 기본 생성자가 안만들어진다.
    // 기본 생성자를 만들어야 함, 혹은 기본값(a=1, b=1 등등)을 줘서 그냥 쓸 수 있게..
    Fraction frac;
    // frac.print();

    // copy initialization: 연산자 오버로딩 정의 필요, not recommended
    Fraction one_thirds2 = Fraction{1, 3};
    one_thirds2.print();

    // 차이점
    // 변수가 public일 경우 가능, uniform initialization으로 **생성자가 없이** 초기화 가능
    // 변수가 private일 경우는 불가능

    // 변수 접근자에 상관없이 생성자가 있을 때 {}, () 모두 가능한데, {}가 자료형변환에 있어 더 엄격하게 작용함(더 좋음)
    Fraction one_thirds3{1.0, 3};
    Fraction one_thirds4(2.0, 4);
*/

    First fir;

    return 0;
}