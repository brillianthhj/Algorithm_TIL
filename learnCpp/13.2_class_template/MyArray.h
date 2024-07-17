#pragma once

#include <assert.h>
#include <iostream>

template<typename T>
class MyArray
{
private:
    int m_length;
    T* m_data;

public:
    MyArray();
    MyArray(const int& length);
    ~MyArray();

    T& operator[](const int& index);
    int getLength();
    void reset();
    void print();
};

#include "MyArray.inc"