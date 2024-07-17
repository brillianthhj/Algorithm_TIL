#include <iostream>
#include <string>
#include "Student.h"
#include "Teacher.h"
#include "Lecture.h"

/*
    - 집합: Aggregation (Has-a)
    - 관계의 형태: 전체(Lecture), 부품(Students, Teacher)
    - 다른 클래스에도 속할 수 있는가? YES (Hobby club / Students, Teacher)
    - 멤버의 존재를 클래스가 관리? NO
    - 방향성: 단방향
*/

int main()
{
    using namespace std;

    // // main 함수의 scope에 있는 local variable, main 함수가 사라지면 소멸됨
    // Student std1("Jack Jack", 0);
    // Student std2("Dash", 1);
    // Student std3("Violet", 2);

    // Teacher teacher1("Prof. Hong");
    // Teacher teacher2("Prof. Good");

    // main이 아닌 다른 곳에서는 동적 할당을 해서 시작함
    Student* std1 = new Student("Jack Jack", 0);
    Student* std2 = new Student("Dash", 1);
    Student* std3 = new Student("Violet", 2);

    Teacher* teacher1 = new Teacher("Prof. Hong");
    Teacher* teacher2 = new Teacher("Prof. Good");

    // Composition Relationship -> aggregation relationship
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(teacher1);
    lec1.registerStudent(std1);
    lec1.registerStudent(std2);
    lec1.registerStudent(std3);

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(teacher2);
    lec2.registerStudent(std1);

    // TODO: implement Aggregation Relationship

    // test
    {
        cout << lec1 << endl;
        cout << lec2 << endl;

        lec2.study();

        cout << lec1 << endl;
        cout << lec2 << endl;
    }

    // TODO: class HobbyClub

    // TODO: delete memory (if necessary)
    delete std1;
    delete std2;
    delete std3;

    delete teacher1;
    delete teacher2;

    return 0;
}