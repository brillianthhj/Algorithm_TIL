#include <iostream>


class Something
{
public:
    // static int s_value;
    // static const int s_value;

    // constexpr는 compile time에 상수를 할당하기 때문에 메모리 주소를 가지고 있지 않음, 메모리 주소 호출하면 에러남
/*
    언제 컴파일 타임 계산을 사용할까?
    1) 상수값 계산 : 프로그램이 실행되는 동안 변경되지 않는 상수 값을 계산할 때
    2) 코드 최적화 : 자주 사용되는 값이나 복잡한 수식을 미리 계산하여 런타임 성능을 최적화 할 때 사용
    3) 컴파일 타임 확인 : 상수를 사용하여 컴파일 타임에 오류를 발견하고 프로그램의 일관성을 유지 (상수식의 유효성 검사, 배열 크기 검증 등)
*/
    static constexpr int s_value = 2;
};

// int Something::s_value = 1; // define in .cpp
// const int Something::s_value = 1;

int main()
{
    // std::cout << &Something::s_value << " " << Something::s_value << std::endl;

    // Something st1;
    // Something st2;

    // // st1.s_value = 2;

    // std::cout << &st1.s_value << " " << st1.s_value << std::endl;
    // std::cout << &st2.s_value << " " << st2.s_value << std::endl;

    // // Something::s_value = 1024;

    // std::cout << &Something::s_value << " " << Something::s_value << std::endl;

    std::cout << Something::s_value << std::endl;

    return 0;
}