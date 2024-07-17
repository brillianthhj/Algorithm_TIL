#pragma once

#include <ostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
    std::string m_name;

    // Teacher teacher;
    // std::vector<Student> students;

    // main()에서 각 Teacher, Students의 고유한 값에서 업데이트를 시키기 위해 포인터를 사용
    Teacher* teacher;
    std::vector<Student*> students;

public:
    Lecture(const std::string& name_in)
        : m_name(name_in)
    {}

    ~Lecture()
    {
        // do NOT delete teacher
        // do NOT delete students
    }

    // void assignTeacher(const Teacher& const teacher_input)
    // {
    //     teacher = teacher_input;
    // }

    void assignTeacher(Teacher* const teacher_input)
    {
        teacher = teacher_input;
    }

    // const Student& student_input : 원래 참조자 선언에는 항상 사전에 변수가 존재해야 하는데, 앞에 const가 붙으면 리터럴 상수 값도 그대로 넣어도 오류 없어서 개꿀임
    // void registerStudent(const Student& student_input)
    // {
    //     students.push_back(student_input);

    //     // &student_input != &students[0]: student_input 값을 복사해와서 vector에 넣는다고 함
    //     // 결론적으로 main()에서 같은 객체에 값을 업뎃하면, 여기도 반영이 돼야 하니까 주소값을 활용한 조치를 취해야 함
    //     // 이 문제를 해결하기 위해 studnet_input의 주소를 받아온다고 함
    // }

    // const Student* student_input : student_input이 가리키는 변수의 값을 역참조해서 못바꾼단 얘기
    // Student* const student_input : pointer인, student_input의 주소값을 못바꾼단 의미
    // const Student* const student_input: 맨 앞이 const이기 때문에 초기화가 무조건 돼야 함,
    //                                     pointer인 student_input의 주소값, student_input이 가리키는 변수값 역참조해서 모두 못바꾼단 얘기
    void registerStudent(Student* const student_input)
    {
        students.push_back(student_input);
    }

    void study()
    {
        std::cout << m_name << " Study " << std::endl << std::endl;

        // for (auto& element : students)  // Note: 'auto element' doesn't update value
        //     element.setIntel(element.getIntel() + 1);

        for (auto element : students) // Note: 'auto element' works
            (*element).setIntel((*element).getIntel() + 1);
            // element->setIntel(element->getIntel() + 1); 과 같음
    }

    friend std::ostream& operator<<(std::ostream& out, const Lecture& lecture)
    {
        out << "Lecture name : " << lecture.m_name << std::endl;

        // out << lecture.teacher << std::endl;
        // for (auto element : lecture.students)
        //     out << element << std::endl;

        out << *lecture.teacher << std::endl;
        for (auto element : lecture.students)
            out << *element << std::endl;
        return out;
    }
};