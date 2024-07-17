#pragma once


template<class T>
class Storage8
{
private:
    T m_array[8];

public:
    void set(const int& index, const T& value)
    {
        m_array[index] = value;
    }

    const T& get(const int& index)
    {
        return m_array[index];
    }
};

template<>
class Storage8<bool>
{
private:
    unsigned char m_data;

public:
    Storage8() : m_data(0) {}

    void set(const int& index, const bool& value)
    {
        // 1 * 2^index 랑 같은 말
        // 쉽게 설명하면, index 번째 비트를 1로 설정
        unsigned char mask = 1 << index;

        if (value)
            // index번째 비트를 m_data 내 bool 값에서 1로 등록
            m_data |= mask;
        else
            // index번째 비트 1을 m_data 내 bool 값에서 해제
            m_data &= ~mask;
    }

    bool get(const int& index)
    {
        unsigned char mask = 1 << index;
        return (m_data & mask) != 0;
    }
};