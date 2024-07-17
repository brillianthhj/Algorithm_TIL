#include <iostream>
#include "Cents.h"

/*
    - int, double, ... , class도 template화 할 수 있음
    - template 정의 후 getMax() 내에 파라메터를 여러 자료형에 대입할 때, 각각이 템플릿 인스턴스가 됨
    - templalte instantiation 이라는 용어가 디버깅 할 때 등장.
*/

template<typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << getMax(1, 2) << std::endl;
    std::cout << getMax(3.14, 1.592) << std::endl;
    std::cout << getMax(1.0f, 3.4f) << std::endl;
    std::cout << getMax('a', 'c') << std::endl;

    std::cout << getMax(Cents(5), Cents(9)) << std::endl;

    return 0;
}