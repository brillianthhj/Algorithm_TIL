#pragma once

#include <ios>
#include <iostream>

template<class T>
class Storage
{
private:
    T m_value;

public:
    Storage(T value)
    {
        m_value = value;
    }

    ~Storage() {}

    void print()
    {
        std::cout << m_value << std::endl;
    }
};

template<>
void Storage<double>::print()
{
    std::cout << "Double Type ";
    std::cout << std::scientific << m_value << std::endl;
}