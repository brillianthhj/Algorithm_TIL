#pragma once
#include "MyArray.h"

template<typename T, unsigned int T_SIZE>
MyArray<T, T_SIZE>::MyArray()
{
    m_data = new T[T_SIZE];
}

template<typename T, unsigned int T_SIZE>
MyArray<T, T_SIZE>::~MyArray()
{
    reset();
}

template<typename T, unsigned int T_SIZE>
void MyArray<T, T_SIZE>::reset()
{
    delete[] m_data;
    m_data = nullptr;
}

template<typename T, unsigned int T_SIZE>
T& MyArray<T, T_SIZE>::operator[](const int& index)
{
    assert(index >= 0);
    assert(index < T_SIZE);
    return m_data[index];
}

template<typename T, unsigned int T_SIZE>
int MyArray<T, T_SIZE>::getLength()
{
    return T_SIZE;
}

template<typename T, unsigned int T_SIZE>
void MyArray<T, T_SIZE>::print()
{
    for (int i = 0; i < T_SIZE; ++i)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}