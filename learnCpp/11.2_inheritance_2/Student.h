#pragma once

#include "Person.h"

/*
    - Student is a Person
*/

class Student : public Person
{
private:
    int m_intel;

    // TODO: add more members like address, phone, favorite food, habits, ...

public:
    // 생성자 외에는 Person 에 있는 것들을 공동으로 사용
    Student(const std::string& name_in = "No name", const int& intel_in = 0)
        : Person(name_in), m_intel(intel_in)
    {}

    void setIntel(const int& intel_in)
    {
        m_intel = intel_in;
    }

    int getIntel()
    {
        return m_intel;
    }

    void study()
    {
        std::cout << getName() << " is studying to level up from " << m_intel << std::endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Student& student)
    {
        out << student.getName() << " " << student.m_intel;
        return out;
    }

};