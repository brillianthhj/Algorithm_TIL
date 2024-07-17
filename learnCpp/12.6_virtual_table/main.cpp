#include <iostream>

/*
    - 동적 바인딩: function pointer를 거쳐가는 구조
    - virtual function이 선언되면 table을 만들고 동적 바인딩을 시킴
    - virtual function이 없으면, 정적 바인딩 시키고 그냥 끝나는 구조
    - virtual table이 생성되고, table에 대한 pointer도 생성됨(_vptr)
*/

class Base
{
private:
    // int m_value;

public:
    // FunctionPointer* _vptr;
    virtual void func1() {};
    virtual void func2() {};
};

class Der : public Base
{
private:
    // by chatGPT, 기존 m_value로부터 얻은 패딩 공간에 m_value2를 집어넣어서 size가 16이 된다고 함
    // int m_value2;

public:
    // FunctionPointer* _vptr;
    void func1() override {};
    void func3() {};
};


int main()
{
    // 1) virtual 표시가 있을 때,
    Base my_base;
    // virtual table에 대한 function pointer, _vptr을 찾은 다음, func1에 대한 포인터를 호출해서 func1()을 실행시킴
    my_base.func1();

    // 2) 자식 클래스의 경우,
    Der my_derived;
    // virtual table에 대한 function pointer, _vptr을 찾은 다음, func1에 대한 포인터를 호출해서 func1()을 실행시킴
    my_derived.func1();
    // virtual table에 대한 function pointer, _vptr을 찾은 다음, func2에 대한 포인터를 부모 클래스에서 호출해서 func2()를 실행시킴
    my_derived.func2();

    // size 비교 : virtual 없을 때
    std::cout << sizeof(Base) << std::endl; // 1
    std::cout << sizeof(Der) << std::endl;  // 1

    // size 비교 : virtual 있을 때
    std::cout << sizeof(Base) << std::endl; // 8: x64 pointer size
    std::cout << sizeof(Der) << std::endl;  // 8
    return 0;
}