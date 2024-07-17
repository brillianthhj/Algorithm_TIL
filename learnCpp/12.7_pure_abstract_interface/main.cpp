#include <iostream>
#include <string>

/*
    - 순수 가상함수(=0): 바디가 없음, 자식 클래스에서 반드시 override를 해줘야 함
    - 추상 기본 클래스: 순수 가상함수가 포함된 클래스, virtual이 하나라도 들어가면 추상 클래스인가 봄. 객체 생성 불가, 멤버 변수와 일반 메서드를 포함할 수 있음.
    - 인터페이스 클래스: 순수 가상함수로만 이뤄진 클래스. 부모 클래스로 값을 형변환 받은 후 자식 클래스의 기능을 불러서 씀. 객체 생성 불가, 멤버 변수와 일반 메서드 포함 불가.
*/

/*
class Animal
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {}

    std::string getName() { return m_name; }

    // 순수 가상함수 만들어주려면, "virtual, = 0" 이게 중요!
    virtual void speak() const = 0; // pure virtual function

    // virtual void speak() const
    // {
    //     std::cout << m_name << " ??? " << std::endl;
    // }
};

// void Animal::speak() const  // the body of the pure virtual function
// {
//     std::cout << " ??? " << std::endl;
// }

class Cat : public Animal
{
public:
    Cat(std::string name)
        : Animal(name)
    {}

    void speak() const override
    {
        std::cout << m_name << " Meow " << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog(std::string name)
        : Animal(name)
    {}

    void speak() const override
    {
        std::cout << m_name << " Woof " << std::endl;
    }
};

class Cow : public Animal
{
public:
    Cow(std::string name)
        : Animal(name)
    {}

    void speak() const override
    {
        std::cout << m_name << " Moooo " << std::endl;
    }
};
*/

class IErorrLog // Interface를 의미하는 I 접두사
{
public:
    virtual bool reportError(const char* errorMessage) = 0; // pure virtual function

    virtual ~IErorrLog() {}
};

class FileErrorLog : public IErorrLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        std::cout << "Writing error to a file : " << errorMessage << std::endl;
        return true;
    }
};

class ConsoleErrorLog : public IErorrLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        std::cout << "Printing error to a console : " << errorMessage << std::endl;
        return true;
    }
};

void doSomething(IErorrLog& log)
{
    log.reportError("Runtime error!!");
}

int main()
{
/*
    // 순수 가상 함수(virtual void speak() = 0;)가 포함된 클래스로 바디가 없어서, 추상 클래스가 돼서 객체 생성 자격이 없음
    // Animal ani("Hi");
    // ani.speak();

    // speak를 반드시 구현해야 한다.
    Cow cow("cow1");
    cow.speak();
*/

    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    // interface로 IErrorLog를 만들어놓고, 각자 자식 클래스들을 받아서 virtual 처리하면, 자식 클래스들의 구현값을 얻을 수 있다.
    doSomething(file_log);
    doSomething(console_log);

    return 0;
}