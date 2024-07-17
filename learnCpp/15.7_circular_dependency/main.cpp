#include <iostream>
#include <memory>
#include <string>

/*
   - std::shared_ptr로 인한 순환 의존성 문제를 std::weak_ptr로 해결하는 방식 소개
   - 그래프 데이터 구조에서는 노드들이 서로를 가리키는 경우가 많습니다. 이때 shared_ptr만 사용하면
     순환 참조로 인해 메모리 누수가 발생할 수 있습니다. 이를 방지하기 위해 weak_ptr를 사용합니다.
*/

class Person
{
    std::string m_name;
    // 소유권이 순환이 돼서, 자기 자신을 지울 수가 없는 상태
    // std::shared_ptr<Person> m_partner;
    std::weak_ptr<Person> m_partner;

public:
    Person(const std::string& name) : m_name(name)
    {
        std::cout << m_name << " created\n";
    }

    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
    {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

        return true;
    }

    const std::shared_ptr<Person> getPartner() const
    {
        // weak pointer는 직접 사용할 수가 없고 락을 해서 shared pointer를 리턴해주면
        // 그 shared pointer로 뭔가를 할 수 있는 구조
        // 순환 의존성을 깨기 위해 이렇게 만들어 짐
        return m_partner.lock();
    }

    const std::string& getName() const
    {
        return m_name;
    }
};

int main()
{
    auto lucy = std::make_shared<Person>("Lucy");
    auto ricky = std::make_shared<Person>("Ricky");

    // shared pointer를 쓰면, memory leak 인 상태로 프로그램이 끝남
    partnerUp(lucy, ricky);

    // weak pointer로 호출하는 상황
    std::cout << "partner : " << lucy->getPartner()->getName() << std::endl;

    return 0;
}