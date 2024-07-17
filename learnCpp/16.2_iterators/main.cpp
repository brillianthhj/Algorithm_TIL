#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

/*
    - iterator 소개
        - 우리가 흔히 아는 선형 자료구조인 vector 뿐만 아니라,
          인덱스 정보가 없는 set, map 내부에 값들을 순차적으로 확인하려 할 때 사용되는 것 같음
    - for each 라 불리는 범위 기반 for loop 순회도 내부적으로 이터레이터를 사용하여 컨테이너의 요소를 순회
*/




int main()
{
    std::vector<int> container;
    for (int i = 0; i < 10; ++i)
        container.push_back(i);

    // 반복자 자체를 변수로 만듬, itr가 포인터 배열 위치라고 생각하면 비슷할 것 같음
    // std::vector<int>::iterator itr; // 얘도 존재 얘는 *itr = 100; 과 같이 변경이 가능
    std::vector<int>::const_iterator itr;
    itr = container.begin();
    while (itr != container.end())
    {
        std::cout << *itr << " ";

        ++itr;
    }
    std::cout << std::endl;

    // 같은 방식
    for(auto itr = container.begin(); itr != container.end(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;

    // 같은 방식 2
    for (auto& e : container)
        std::cout << e << " ";
    std::cout << std::endl;


    // list 도 동일한 iterator 반복자 문법을 사용해서 할 수 있음
    std::list<int> container2;
    for (int i = 10; i < 20; ++i)
        container2.push_back(i);

    for (auto itr = container2.begin(); itr != container2.end(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;

    // set 도 동일한 iterator 반복자 문법을 사용해서 할 수 있음
    std::set<int> container3;
    for (int i = 20; i < 30; ++i)
        container3.insert(i);

    for (auto itr = container3.begin(); itr != container3.end(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;

    // map 도 동일한 iterator 반복자 문법을 사용해서 할 수 있음
    std::map<int, char> container4;
    for (int i = 30; i < 40; ++i)
        container4.insert(std::make_pair(i, char(i + 65)));

    for (auto itr = container4.begin(); itr != container4.end(); ++itr)
        std::cout << (*itr).first << " " << (*itr).second << std::endl;


    return 0;
}