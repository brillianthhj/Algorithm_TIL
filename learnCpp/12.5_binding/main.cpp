#include <iostream>

/*
    - dynamic binding: 다형성을 지원하기 위해 가상함수를 활용할 때 주로 사용. 포인터를 써서 구현하는 것 같음.
                       런타임에 결정됨, 느리지만 프로그래밍이 유연해짐
    - static binding: 컴파일 타임에 결정됨, 빠름
*/


int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}


int main()
{
    int x, y;
    std::cout << "input x, y : ";
    std::cin >> x >> y;

    int op;
    std::cout << "0 : add, 1 : subtract, 2 : multiply" << std::endl;
    std::cin >> op;

    // static binding (early binding)
    // int result;
    // switch (op)
    // {
    //     case 0: result = add(x, y); break;
    //     case 1: result = subtract(x, y); break;
    //     case 2: result = multiply(x, y); break;
    // }

    // std::cout << result << std::endl;

    // dynamic binding (late binding): function pointer에 저장돼 있는 주소를 보고 그 주소를 쫓아가서 그 주소 자리에 있는 함수를 실행시킴
    int (*func_ptr)(int, int) = nullptr;
    switch (op)
    {
        case 0: func_ptr = add; break;
        case 1: func_ptr = subtract; break;
        case 2: func_ptr = multiply; break;
    }

    int result = func_ptr(x, y);
    std::cout << result << std::endl;

    return 0;
}