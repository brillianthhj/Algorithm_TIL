#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/*
    - STL algorithms
*/

int main()
{
    // std::vector<int> container;
    std::list<int> container;
    for (int i = 0; i < 10; ++i)
        container.push_back(i);

    // auto itr = li.begin();
    // list<int>::const_iterator itr;
    auto itr = std::min_element(container.begin(), container.end());
    std::cout << *itr << std::endl;

    itr = std::max_element(container.begin(), container.end());
    std::cout << *itr << std::endl;

    std::cout << std::endl;

    // container(vector) 대신 user defined data type 에서는 비교 연산자가 오버로딩 돼야만 사용 가능
    itr = std::find(container.begin(), container.end(), 3);
    container.insert(itr, 128);

    for (auto& e : container)
        std::cout << e << " ";
    std::cout << std::endl;

    // sort(container.begin(), container.end());
    container.sort();

    for (auto& e : container)
        std::cout << e << " ";
    std::cout << std::endl;

    // reverse(container.begin(), container.end());
    container.reverse();

    for (auto& e : container)
        std::cout << e << " ";
    std::cout << std::endl;


    return 0;
}