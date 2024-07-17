#pragma once

#include <string>
#include "Position2D.h"

class Monster
{
private:
    std::string m_name; // char* data, int length
    Position2D m_location;
    // int m_x;    // location
    // int m_y;

public:
    Monster(const std::string name_in, const Position2D& pos_in)
        : m_name(name_in),
          m_location(pos_in)
    {}

    void moveTo(const Position2D& pos_target)
    {
        // m_x = x_target;
        // m_y = y_target;
        // Monster가 location의 옮기는 정보를 자세하게 알 필요가 없음
        //m_location.set(pos_target);
        // TODO: operator =
        std::cout << "m_location: " << &m_location << std::endl;
        std::cout << "pos_target: " << &pos_target << std::endl;
        m_location = pos_target;
        std::cout << "m_location: " << &m_location << std::endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Monster& monster)
    {
        out << monster.m_name << " " << monster.m_location;
        return out;
    }
};