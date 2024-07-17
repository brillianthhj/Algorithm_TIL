#pragma once

#include "Person.h"

/*
    - Teacher is a Person
*/

class Teacher : public Person
{
private:
    // TODO: more members like home address, salary, age, evaluation, etc.

public:
    // 생성자 외에는 Person 에 있는 것들을 공동으로 사용
    Teacher(const std::string& name_in = "No name")
        : Person(name_in)
    {}

    void teach()
    {
        std::cout << getName() << " is teaching." << std::endl;
    }


    friend std::ostream& operator << (std::ostream& out, const Teacher& teacher)
    {
        out << teacher.getName();
        return out;
    }

};