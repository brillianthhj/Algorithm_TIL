#include <iostream>
#include "Storage.h"

/*
    - 함수 템플릿 특수화: 특별한 자료형에 대해서는 다른 기능을 구현하고 싶을 때
*/


template<typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

// 특별한 경우 char에 해당하면 얘를 사용해라.
template<>
char getMax(char x, char y)
{
    std::cout << "Warning: comparing chars" << std::endl;
    return (x > y) ? x : y;
}



int main()
{
    // 들어가는 파라메터에 따라 자동으로 instantiation 함
    // std::cout << getMax(1, 2) << std::endl;
    // std::cout << getMax<double>(1, 2) << std::endl;

    // std::cout << getMax('a', 'b') << std::endl;

    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    nValue.print();
    dValue.print();

    return 0;
}