#include "Calc.h"

Calc::Calc(int init_value)
 : m_value(init_value) {}

Calc& Calc::add(const int& value)
{
    m_value += value;
    return *this;
}

Calc& Calc::sub(const int& value)
{
    m_value -= value;
    return *this;
}

Calc& Calc::mult(const int& value)
{
    m_value *= value;
    return *this;
}

void Calc::print()
{
    std::cout << m_value << std::endl;
}
