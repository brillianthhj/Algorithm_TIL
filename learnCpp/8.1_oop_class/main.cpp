#include <iostream>
#include <string>
#include <vector>

// Friend : name, address, age, height, weight, ...

class Friend
{
public:     // access specifier (public, private, protected)
    std::string m_name;
    std::string m_address;
    int         m_age;
    double      m_height;
    double      m_weight;

    void print()
    {
        std::cout << m_name << " " << m_address << " " << m_age << " "
                << m_height << " " << m_weight << std::endl;
    }
};

void print(const Friend &fr)
{
    std::cout << fr.m_name << " " << fr.m_address << " " << fr.m_age << " "
              << fr.m_height << " " << fr.m_weight << std::endl;
}

void print(const std::string &m_name, const std::string &m_address, const int &m_age,
    const double &m_height, const double &m_weight)
{
    std::cout << m_name << " " << m_address << " " << m_age << " "
              << m_height << " " << m_weight << std::endl;
}

int main()
{
    Friend jj{"Jack Jack", "Uptown", 2, 30, 10}; // instanciation
    jj.print();

    std::vector<Friend> my_friends;
    my_friends.resize(2);

    my_friends[0].print();
    my_friends[1].print();

    for(auto &element : my_friends)
        element.print();

    // print(jj.m_name, jj.m_address, jj.m_age, jj.m_height, jj.m_weight);

    // std::vector<std::string> name_vec;
    // std::vector<std::string> addr_vec;
    // std::vector<int>         age_vec;
    // std::vector<double>      height_vec;
    // std::vector<double>      weight_vec;

    // print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);

    return 0;
}