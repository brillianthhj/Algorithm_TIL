#include <iostream>
#include <string>

// class Simple
// {
// private:
//     int m_id;

// public:
//     Simple(const int& id_in)
//         : m_id(id_in)
//     {
//         std::cout << "Constructor " << m_id << std::endl;
//     }

//     ~Simple()
//     {
//         std::cout << "Destructor " << m_id << std::endl;
//     }
// };

class IntArray
{
private:
    int *m_arr = nullptr;
    unsigned int m_length = 0;

public:
    IntArray(const int length_in)
    {
        m_length = length_in;
        m_arr = new int[m_length];
    }

    ~IntArray()
    {
        if (m_arr != nullptr)
            delete[] m_arr;
    }

    unsigned int size() { return m_length; }


};

int main()
{
    // Simple s1(0);
    // Simple *s1 = new Simple(0);
    // Simple s2(1);

    // delete s1;

    while (true)
    {
        IntArray my_int_arr(10000);
    }

    /*
        객체를 동적할당해서 해제하는 유형들에 대한 예제
        1. 단일 객체의 동적 할당과 해제 :
        {
            MyClass* myObject = new MyClass();
            ...
            delete myObject;
        }

        2. 배열의 동적 할당과 해제 :
        {
            MyClass *myArray = new Myclass[5];
            ...
            delete[] myArray;
        }

        3. 스마트포인터: std::unique_ptr
        {
            std::unique_ptr<MyClass> myObject = std::make_unique<MyClass>();
            (자동해제)
        }

        4. 스마트포인터: std::shared_ptr
        {
            std::shared_ptr<MyClass> myObject1 = std::make_shared<MyClass>();
            (자동해제)
        }

        5. 사용자 정의 스마트 포인터
        {
            template <typename T>
            class SmartPointer
            {
            private:
                T* m_ptr;
            public:
                explicit SmartPointer(T* ptr = nullptr) : m_ptr(ptr) {}
                ~SmartPointer() { delete m_ptr; }

                T& operator*() { return *m_ptr; }
                T* operator->() { return m_ptr; }
            };

            class MyClass
            {
            public:
                MyClass() { std::cout << "Constructor" << std::endl; }
                ~MyClass() { std::cout << "Destructor" << std::endl; }
            };

            int main()
            {
                SmartPointer<MyClass> myObject(new MyClass());

                ...  // 스마트 포인터가 범위를 벗어나면 자동으로 메모리 해제

                return 0;
            }
        }
     */
    return 0;
}