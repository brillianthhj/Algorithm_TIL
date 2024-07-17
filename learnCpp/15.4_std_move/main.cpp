#include "AutoPtr.h"
#include "Resource.h"
#include <iostream>
#include <vector>

/*
    - std::move : l-value를 r-value로 리턴을 해 줌
        - 그냥 주소값만 넘겨도 되는 경우
        - 다음에 l-value 객체를 사용 안하는 경우
*/

template<class T>
void MySwap(T& a, T& b)
{
    // // copy constructor
    // T tmp = a;
    // // copy assignment
    // a = b;
    // b = tmp;

    T tmp{ std::move(a) };
    a = std::move(b);
    b = std::move(tmp);
}


int main()
{
//     {
//         AutoPtr<Resource> res1(new Resource(10000000));

//         std::cout << res1.m_ptr << std::endl;

//         AutoPtr<Resource> res2 = std::move(res1);

//         std::cout << res1.m_ptr << std::endl;
//         std::cout << res2.m_ptr << std::endl;
//     }

    // {
    //     AutoPtr<Resource> res1(new Resource(3));
    //     res1->setAll(3);

    //     AutoPtr<Resource> res2(new Resource(5));
    //     res2->setAll(5);

    //     res1->print();
    //     res2->print();

    //     MySwap(res1, res2);

    //     res1->print();
    //     res2->print();
    // }

    // {
    //     std::vector<std::string> v;
    //     std::string str = "Hello";

    //     v.push_back(str);

    //     std::cout << str << std::endl;
    //     std::cout << v[0] << std::endl;

    //     v.push_back(std::move(str));

    //     // std::move(str) 하면서 str이 사라졌기 때문에, 빈칸이 된다.
    //     std::cout << str << std::endl;
    //     std::cout << v[0] << " " << v[1] << std::endl;
    // }


    {
        std::string x{"abc"};
        std::string y{"de"};

        std::cout << "x : " << x << std::endl;
        std::cout << "y : " << y << std::endl;

        MySwap(x, y);

        std::cout << "x : " << x << std::endl;
        std::cout << "y : " << y << std::endl;
    }

    return 0;
}