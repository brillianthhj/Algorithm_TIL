#pragma once

#include <assert.h>
#include <iostream>

// template parameter가 들어가는 자리 2개
// 이렇게 하면 컴파일 타임에 T_SIZE 가 결정이 됨
template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
    // int m_length;
    T* m_data;

public:
    MyArray();

    ~MyArray();

    void reset();

    T& operator[](const int& index);

    int getLength();

    void print();
};

#include "MyArray_Impl.h"