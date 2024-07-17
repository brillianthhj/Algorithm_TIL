#include <iostream>
#include <string.h>

/*
    - 템플릿을 부분적으로 특수화하기
    - 상속을 받아서 템플릿 필요한 부분만 정해주고, 원하는 함수 재정의
*/

template<class T, int size>
class StaticArray_BASE
{
private:
    T m_array[size];

public:
    T* getArray() { return m_array; }

    T& operator[](const int& index)
    {
        return m_array[index];
    }

    virtual void print()
    {
        for (int i = 0; i < size; ++i)
            // array[i]는 StaticArray 객체의 operator[] 를 오버로딩한 것임
            std::cout << (*this)[i] << ' ';
        std::cout << std::endl;
    }
};

// template<typename T, int size>
// void print(StaticArray<T, size>& array)
// {
//     for (int i = 0; i < size; ++i)
//         // array[i]는 StaticArray 객체의 operator[] 를 오버로딩한 것임
//         std::cout << array[i] << ' ';
//         // std::cout << array.getArray()[i] << std::endl;
//     std::cout << std::endl;
// }

// // template 지정자 "T, size" 중에 T를 char인 경우 특정해 아래 구현을 조금 바꿀 수 있음
// template<int size>
// void print(StaticArray<char, size>& array)
// {
//     for (int i = 0; i < size; ++i)
//         std::cout << array[i];
//         // std::cout << array.getArray()[i] << std::endl;
//     std::cout << std::endl;
// }

template<class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{
};

// print()만 specialization
// 상속을 받아서 템플릿 설정까지 해주고(<char, size>) 함수 override 진행
template<int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{

public:
    void print() override
    {
        for (int i = 0; i < size; ++i)
            // array[i]는 StaticArray 객체의 operator[] 를 오버로딩한 것임
            std::cout << (*this)[i];
        std::cout << std::endl;
    }
};

int main()
{
    StaticArray<int, 4> int4;
    int4[0] = 1;
    int4[1] = 2;
    int4[2] = 3;
    int4[3] = 4;

    int4.print();

    StaticArray<char, 14> char14;
    char14[0] = 'H';
    char14[1] = 'e';
    // ...
    strncpy(char14.getArray(), "Hello, World", 14);
    char14.getArray()[13] = '\0';

    char14.print();

    return 0;
}