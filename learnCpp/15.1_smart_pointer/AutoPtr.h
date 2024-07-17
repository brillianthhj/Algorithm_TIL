#pragma once

// std::auto_ptr<int> 과 유사한 클래스
// c++ 11부터는 안쓰기로 함..

template<class T>
class AutoPtr
{
public:
    T* m_ptr = nullptr;

public:
    AutoPtr(T* ptr = nullptr)
        : m_ptr(ptr)
    {}

    ~AutoPtr()
    {
        if (m_ptr != nullptr)   delete m_ptr;
    }

    // AutoPtr(AutoPtr &a)
    // {
    //     m_ptr = a.m_ptr;
    //     a.m_ptr = nullptr;
    // }

    // AutoPtr& operator=(AutoPtr& a)
    // {
    //     if (&a == this)
    //         return *this;

    //     delete m_ptr;
    //     m_ptr = a.m_ptr;
    //     a.m_ptr = nullptr;
    //     return *this;
    // }

    // 이동 생성자
    AutoPtr(AutoPtr&& a) noexcept
    {
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }

    // 이동 대입 연산자
    AutoPtr& operator=(AutoPtr&& a) noexcept
    {
        if (&a == this)
            return *this;

        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }

    // 복사 생성자 삭제
    AutoPtr(const AutoPtr&) = delete;

    // 복사 대입 연산자 삭제
    AutoPtr& operator=(const AutoPtr&) = delete;

    // pointer처럼 동작할 수 있게 overloading
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};