#include <iostream>
#include <string>

class Student
{
private:
    int         m_id;
    std::string m_name;

public:
    Student(const std::string& name_in)
    // 안좋은 코드, 초기화는 한번만 해주면 좋음, m_id를 나중에 또 변경해야함
    //    : m_id(0), m_name(name_in)
    // 위임생성자: 생성자가 생성자를 호출
    //    : Student(0, name_in)
    {
        init(0, name_in);
    }

    Student(const int& id_in, const std::string& name_in)
    //    : m_id(id_in), m_name(name_in)
    {
        init(id_in, name_in);
    }

    void init(const int& id_in, const std::string& name_in)
    {
        m_id = id_in;
        m_name = name_in;
    }

    void print()
    {
        std::cout << m_id << " " << m_name << std::endl;
    }
};

int main()
{
    Student st1(0, "Jack Jack");
    st1.print();

    Student st2("Lily");
    st2.print();

    return 0;
}