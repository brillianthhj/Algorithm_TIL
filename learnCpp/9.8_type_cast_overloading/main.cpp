#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0)
    {
        m_cents = cents;
    }

    int getCents() { return m_cents; }
    void setCents(const int& cents) { m_cents = cents; }

    operator int()
    {
        std::cout << "cast here" << std::endl;
        return m_cents;
    }
};

class Dollar
{
private:
    int m_dollars;

public:
    Dollar(const int& input) : m_dollars(input) {}

    operator Cents()
    {
        return Cents(m_dollars * 100);
    }
};

void printInt(const int &value)
{
    std::cout << value << std::endl;
}

int main()
{
    Cents cents(7);
    // cents가 int 로 형변환 되면서 operator int() 호출
    printInt(cents);

    Dollar dollar(3);
    // dollar가 Cents로 형변환 되면서, operator Cents() 호출
    Cents cents2 = dollar;
    // std::cout 이 Cents 객체를 바로 출력할 수 없어서(사용자 정의 타입에 대해 기본 출력 연산자가 없음)
    // Cents 객체를 출력하기 위해 사용할 수 있는 변환 연산자가 있는지 찾음, 따라서 operator int() 호출
    std::cout << cents2 << std::endl;

    return 0;
}