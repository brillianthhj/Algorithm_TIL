#include <algorithm>
#include <chrono>
#include <iostream>

class B
{
private:
    int m_b;

public:
    B(const int& m_b_in)
    : m_b(m_b_in)
    {
        std::cout << m_b << std::endl;
    }
};

class Something
{
private:
    int     m_i = 100;
    double  m_d = 100.0;
    char    m_c = 'F';
    int     m_arr[5] = {100, 200, 300, 400, 500};
    B       m_b{1024};

public:
    Something()
    //: m_i(1), m_d(3.14), m_c('a')
    : m_i{1}, m_d{3.14}, m_c{'a'}
    , m_arr{1, 2, 3, 4, 5}, m_b(m_i - 1)   // 형변환이 안된다!, 자동으로 캐스팅이 안된다.
    {
        m_i *= 3;
        m_d *= 3.0;
        m_c += 3;
    }

    void print()
    {
        std::cout << m_i << " " << m_d << " " << m_c << std::endl;
        for(auto& e : m_arr)
            std::cout << e << " ";
        std::cout << std::endl;
    }
};

int main()
{
    Something som;
    som.print();

    return 0;
}