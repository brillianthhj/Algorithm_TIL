#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

/*
   - 표준 템플릿 라이브러리(STL)와 컨테이너 소개
   - standard C++ library vs STL
        - STL : Algorithms, Containers, Functions, Iterators
        - 나머지는 standard C++ library
*/

void sequence_containers()
{
    // vector
    {
        std::vector<int> vec;    // #include vector
        for (int i = 0; i < 10; ++i)
            vec.push_back(i);

        for (auto& e : vec)
            std::cout << e << " ";
        std::cout << std::endl;
    }

    // deque
    {
        std::deque<int> deq;    // #include <deque>
        for (int i = 0; i < 10; ++i)
        {
            deq.push_back(i);
            deq.push_front(i);
        }

        for (auto& e : deq)
            std::cout << e << " ";
        std::cout << std::endl;
    }
}

void associative_containers()
{
    // set
    {
        std::set<std::string> str_set;

        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello");

        std::cout << str_set.size() << std::endl;

        for (const auto& e : str_set)
            std::cout << e << " ";
        std::cout << std::endl;
    }

    // multiset : duplication is allowed
    {
        std::multiset<std::string> str_set;

        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello");

        std::cout << str_set.size() << std::endl;

        for (const auto& e : str_set)
            std::cout << e << " ";
        std::cout << std::endl;
    }

    // map : key/value (json)
    {
        std::map<char, int> map;
        map['a'] = 10;
        map['b'] = 20;
        map['c'] = 50;

        std::cout << map['a'] << std::endl;

        map['a'] = 100;

        std::cout << map['a'] << std::endl;

        for (auto& e : map)
            std::cout << e.first << " " << e.second << " ";
        std::cout << std::endl;
    }

    // multimap : duplicated keys
    {
        std::multimap<char, int> map;
        map.insert(std::pair<char, int>('a', 10));
        map.insert(std::pair<char, int>('b', 10));
        map.insert(std::pair<char, int>('c', 10));
        map.insert(std::pair<char, int>('a', 100));

        std::cout << map.count('a') << std::endl;

        for (auto& e : map)
            std::cout << e.first << " " << e.second << " ";
        std::cout << std::endl;
    }
}

void container_adapters()
{
    // stack
    {
        std::cout << "Stack" << std::endl;

        std::stack<int> stack;
        stack.push(1);        // push adds a copy : 사용자 정의 클래스를 복사해서 집어넣음
        stack.emplace(2);       // emplace constructs a new object
        stack.emplace(3);

        std::cout << stack.top() << std::endl;
        stack.pop();
        std::cout << stack.top() << std::endl;
    }

    // queue
    {
        std::cout << "Queue" << std::endl;

        std::queue<int> queue;
        queue.push(1);
        queue.push(2);
        queue.push(3);

        std::cout << queue.front() << " " << queue.back() << std::endl;
        queue.pop();
        std::cout << queue.front() << " " << queue.back() << std::endl;
    }

    // Priority queue : sorting
    {
        std::cout << "Priority queue" << std::endl;

        // int 대신에 사용자 정의 클래스에 대해 대소비교 오버로딩을 통해 크기 를 비교할 수 있음
        std::priority_queue<int> queue;

        for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
            queue.push(n);

        for (int i = 0; i < 10; ++i)
        {
            std::cout << queue.top() << std::endl;
            queue.pop();
        }
    }

}


int main()
{
    // sequence_containers();

    // associative_containers();

    container_adapters();

    return 0;
}