#include <iostream>
#include <string>

/*
    1) const가 class와 사용이 될 때 어떻게 되는가?
    2) class의 instance or object 자체를 const로 만들기도 하는데 이때는 member variable들이 const가 되는 효과
    3) member function이 const가 된다는 것은 그 함수 안에서 member variable을 바꾸지 않는다는 뜻
    4) reference 보낼때도 const 쓴 것과 안쓴 것의 차이 확인
    5) 파라미터로 변수가 넘어갈 때 복사가 되면서 오버헤드가 있는데, 복사하지 않고 참조로 넘기면 좋다.
        - class의 copy constructor의 구조 설명 완료
    6) const function vs non-const function 둘 간에는 오버로딩이 된다.
*/

class Something
{
public:
/*
    int m_value = 0;

    // copy constructor가 숨어있음
    Something(const Something& st_in)
    {
        // m_value = st_in.m_value;
        m_value = st_in.getValue();

        std::cout << "Copy constructor" << std::endl;
    }

    Something()
    {
        std::cout << "Constructor" << std::endl;
    }

    void setValue(const int& value) { m_value = value; }

    // m_value를 바꾸지 않는다!!
    int getValue() const
    {
        return m_value;
    }
 */

    std::string m_value = "default";

    // 리턴타입이 달라도 오버로딩이 안되는데, const냐 아니냐는 오버로딩이 가능!
    // member function을 const로 만드는 경우는 return도 const로 만드는 것이 일반적임
    const std::string& getValue() const
    {
        std::cout << "const version" << std::endl;
        return m_value;
    }

    std::string& getValue()
    {
        std::cout << "non-const version" << std::endl;
        return m_value;
    }
};


/*

// 복사하지 말고 효율을 위해 값을 그대로 받아와라.
// void print(Something st)
void print(const Something& st)
{
    std::cout << &st << std::endl;
    std::cout << st.getValue() << std::endl;
}

*/

int main()
{
    // const Something something;
    // // something.setValue(3);

    // class를 const로 바꿨을 때, const 멤버 함수만 호출 가능
    // const를 쓸 수 있으면 많이 쓸수록 좋다!, 디버깅에 유리, 실수 방지
    // std::cout << something.getValue() << std::endl;

/*
    Something something;
    std::cout << &something << std::endl;
    print(something);
*/

    Something something;
    something.getValue() = "new default";
    std::cout << something.getValue() << std::endl;

    // class를 const로 만드는 건 member variable들이 const가 되는 것과 같은 효과
    const Something something2;
    something2.getValue(); // = 20; 는 const라서 할 수가 없음

    return 0;
}