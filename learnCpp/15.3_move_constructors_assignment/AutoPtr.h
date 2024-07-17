#pragma once

#include <iostream>


template<class T>
class AutoPtr
{
public:
    T* m_ptr;

public:
    AutoPtr(T* ptr = nullptr)
        : m_ptr(ptr)
    {
        std::cout << "AutoPtr default constructor" << std::endl;
    }

    ~AutoPtr()
    {
        std::cout << "AutoPtr destructor" << std::endl;

        if (m_ptr != nullptr)   delete m_ptr;
    }

    AutoPtr(const AutoPtr& a)
    {
        std::cout << "AutoPtr copy constructor" << std::endl;

        // deep copy : 느려질거다..
        m_ptr = new T;
        // Resource/operator=() 호출
        *m_ptr = *a.m_ptr;
    }

    AutoPtr& operator=(const AutoPtr& a)
    {
        std::cout << "AutoPtr copy assignment" << std::endl;

        if (&a == this)
            return *this;

        if (m_ptr != nullptr)
            delete m_ptr;

        // deep copy
        m_ptr = new T;
        // Resource/operator=() 호출
        *m_ptr = *a.m_ptr;

        return *this;
    }

    // 이동 생성자
    AutoPtr(AutoPtr&& a)
        : m_ptr(a.m_ptr)
    {
        // move 소유권 이전
        a.m_ptr = nullptr;

        std::cout << "AutoPtr move constructor" << std::endl;
    }

    // 이동 대입 연산자
    AutoPtr& operator=(AutoPtr&& a)
    {
        std::cout << "AutoPtr move assignment" << std::endl;

        if (&a == this)
            return *this;

        if (!m_ptr)
            delete m_ptr;

        // shallow copy
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }

    // // 복사 생성자 삭제
    // AutoPtr(const AutoPtr&) = delete;

    // // 복사 대입 연산자 삭제
    // AutoPtr& operator=(const AutoPtr&) = delete;

    // pointer처럼 동작할 수 있게 overloading
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};