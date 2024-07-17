#pragma once

#include <iostream>
#include <ostream>

class Position2D
{
private:
    int m_x;
    int m_y;

public:
    Position2D(const int& x_in, const int& y_in)
        :m_x(x_in), m_y(y_in)
    {}

    // TODO: overload operator =
    /*
    // 생략된, 기본 대입 연산자 정의
    Position2D& operator=(const Position2D& other)
    {
        if (this != &other)
        {
            this->m_x = other.m_x;
            this->m_y = other.m_y;
        }
        return *this;
    }
    */

    void set(const Position2D& pos_target)
    {
        set(pos_target.m_x, pos_target.m_y);
        // m_x = pos_target.m_x;
        // m_y = pos_target.m_y;
        // 이렇게도 할 수 있지만, 나중에 set 함수의 경우 바꿔야 할 부분이 있으면 여러군데 수정을 해야 하므로, 있는 함수 갖다쓰는게 더 좋다고 함!
    }

    void set(const int& x_target, const int& y_target)
    {
        m_x = x_target;
        m_y = y_target;
    }

    friend std::ostream& operator << (std::ostream& out, const Position2D& pos2d)
    {
        out << pos2d.m_x << " " << pos2d.m_y;
        return out;
    }
};