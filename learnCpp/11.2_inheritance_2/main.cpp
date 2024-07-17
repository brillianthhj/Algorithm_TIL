#include "Teacher.h"
#include "Student.h"

/*
    - is-a relationship
    - 중복되는 기능이 있을 때, 수정하는 관점에서 한군데에서만 수정하면 돼서 객체지향 관점에서 용이
*/

int main()
{
    Teacher teacher("Dr. H");
    Student student("Jack Jack");
    std::cout << teacher << std::endl;
    std::cout << student << std::endl;

    student.setName("Jack Jack 2");
    std::cout << student << std::endl;

    student.doNothing();
    teacher.doNothing();

    student.study();
    teacher.teach();

    Person person;
    person.setName("Mr. Incredible");
    std::cout << person.getName() << std::endl;

    return 0;
}