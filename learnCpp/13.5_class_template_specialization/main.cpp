#include <iostream>
#include "Storage.h"

/*
    - 클래스 템플릿 특수화: 새로운 클래스를 더 추가하는 형태이긴 함
    - template<>
      class A<bool> {} ...
*/


template<typename T>
class A
{
public:
    A() {}

    A(const T& input)
    {}

    void doSomething()
    {
        std::cout << typeid(T).name() << std::endl;
    }

    void test()
    {}
};

// class specialization
template<>
class A<char>
{
public:
    A() {}

    A(const char& input)
    {}

    void doSomething()
    {
        std::cout << "Char type specialization" << std::endl;
    }
};


int main()
{
/*
    A<int>      a_int;
    A<double>   a_double;
    A<char>     a_char;

    // 자동으로 A<datatype> 생성해줌
    A a_int2(1);
    A a_double2(2.3);
    A a_char2('c');

    a_int.test();
    a_double.test();
    // a_char.test();

    a_int.doSomething();
    a_double.doSomething();
    a_char.doSomething();
*/

    // Define a Storage8 for integers
    Storage8<int> intStorage;

    for (int count = 0; count < 8; ++count)
        intStorage.set(count, count);

    for (int count = 0; count < 8; ++count)
        std::cout << intStorage.get(count) << std::endl;

    std::cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << std::endl;

    // Define a Storage8 for bool
    Storage8<bool> boolStorage;
    for (int count = 0; count < 8; ++count)
        boolStorage.set(count, count & 3);

    for (int count = 0; count < 8; ++count)
        std::cout << (boolStorage.get(count) ? "true" : "false") << std::endl;

    std::cout << "Sizeof Storage8<bool>" << sizeof(Storage8<bool>) << std::endl;

    std::cout << (0b0110 >> 2) << std::endl;// bitwise : 6 / 2^2 = 6 / 4 = 1
    std::cout << (5 & 12) << std::endl;     // bitwise AND : 0101 & 1100 = 0100 = 4
    std::cout << (5 & 3) << std::endl;      // bitwise AND : 0101 & 0011 = 0001 = 1
    std::cout << (5 ^ 12) << std::endl;     // bitwise XOR : 1001 = 9

    return 0;
}