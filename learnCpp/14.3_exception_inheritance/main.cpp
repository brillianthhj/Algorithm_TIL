#include <iostream>

/*
    - 사용자 정의 자료형(예외 클래스)와 상속
    - throw 할 때 사용자 정의 클래스() 호출하고, catch문에서 그 객체 자료형 받아서 객체로부터 함수 호출 가능
*/

class Exception
{
public:
    virtual void report() const
    {
        std::cerr << "Excetpion report" << std::endl;
    }
};

class ArrayException : public Exception
{
public:
    void report() const override
    {
        std::cerr << "Array exception" << std::endl;
    }
};



class MyArray
{
private:
    int m_data[5];

public:
    int& operator[](const int& index)
    {
        // 멤버 함수 안에서 throw를 할 수 있음
        if (index < 0 || index >= 5)
            // throw -1;
            // throw Exception();
            throw ArrayException();

        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;

    try {
        my_array[100];
    } catch (const int& x) {
        std::cerr << "Exception " << x << std::endl;
    }
    catch (const Exception& e)
    {
        std::cout << "doSomething()" << std::endl;
        e.report();
        // throw e; // main()에서 또 catch를 받을 수 있게 던짐
        throw;  // 객체 잘림 현상이 안생기게 throw e 대신에 사용
    }
}

int main()
{
    try {
        doSomething();
    } catch (const Exception& e) {
        std::cout << "main()" << std::endl;
        e.report();
    }

    return 0;
}