#include <iostream>
#include <string>

/*
    - 동적 형변환(Dynamic Casting)
    - 다형성을 사용하다 보면 종종 자식 클래스의 포인터를 부모 클래스의 포인터로
      바꿔줬다가 다시 자식 포인터의 클래스로 바꿔줄 필요가 생김
    - static_cast vs dynamic_cast: 가급적 안쓰고, functional 대체..?
        - static_cast :
            - 컴파일 타임에 타입 변환을 수행합니다.
            - 기본 타입 간의 변환, 명시적 생성자 호출, 상속 계층 구조 내에서의 변환 등에 사용됩니다.
            - 안전성 검사를 수행하지 않으므로, 올바르지 않은 타입 변환은 정의되지 않은 동작(Undefined Behavior)을 초래할 수 있습니다.
            - 주로 상속 계층 구조 내에서 기반 클래스 포인터를 파생 클래스 포인터로 캐스팅하거나, 그 반대의 경우에 사용됩니다.
            - 런타임 오버헤드가 없습니다.
        - dynamic_cast(권장) :
            - 런타임에 타입 변환을 수행합니다.
            - 주로 다형성(Polymorphism)을 지원하기 위해 사용됩니다.
            - 타입의 안전성을 검사하여, 올바르지 않은 타입 변환 시 nullptr을 반환하거나 예외를 발생시킵니다.
            - 주로 상속 계층 구조 내에서 기반 클래스 포인터를 파생 클래스 포인터로 안전하게 캐스팅할 때 사용됩니다.
            - 런타임 타입 정보(RTTI, Run-Time Type Information)를 필요로 하며, 이를 통해 타입 검사를 수행합니다.
            - 런타임 오버헤드가 있을 수 있습니다.
*/

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        std::cout << "I'm Base" << std::endl;
    }
};

class Derived1 : public Base
{
public:
    int m_j = 1024;

    virtual void print() override
    {
        std::cout << "I'm derived 1" << std::endl;
    }
};

class Derived2 : public Base
{
public:
    std::string m_name = "Dr. Two";

    virtual void print() override
    {
        std::cout << "I'm derived 2" << std::endl;
    }
};

int main()
{
    Derived1 d1;
    d1.m_j = 2048;
    Base* base = &d1;
    // std::cout << base->m_j << std::endl;

    auto* base_to_d1 = dynamic_cast<Derived1*>(base);
    std::cout << base_to_d1->m_j << std::endl;
    // 가급적 안하는게..
    base_to_d1->m_j = 256;

    std::cout << d1.m_j << std::endl;

    // Derived2를 dynamic_cast 해보자. Derived1 -> Base -> Derived2라서 안됨.
    // casting 안되면 nullptr 뿌려줌
    auto* base_to_d2 = dynamic_cast<Derived2*>(base);
    if (base_to_d2 != nullptr)
        std::cout << base_to_d2->m_name << std::endl;
    else
        std::cout << "Failed" << std::endl;

    // segmentation fault
    // base_to_d2->print();

    return 0;
}