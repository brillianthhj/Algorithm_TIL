#include <iostream>
#include <string>

/*
    - [ ] is an Animal
*/

class Animal
{
protected:
    std::string m_name;

public:
    Animal(const std::string& name_in)
        : m_name(name_in)
    {}

public:
    std::string getName() { return m_name; }

    // 부모 클래스로 형변환 했을 때, 자식 클래스의 함수를 고대로 쓸 수 있음
    virtual void speak() const
    {
        std::cout << m_name << " ??? " << std::endl;
    }
};

class Cat : public Animal
{
public:
    Cat(const std::string& name_in)
        : Animal(name_in)
    {}

    void speak() const
    {
        std::cout << m_name << " Meow " << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog(const std::string& name_in)
        : Animal(name_in)
    {}

    void speak() const
    {
        std::cout << m_name << " Woof " << std::endl;
    }
};

int main()
{
    // Animal animal("my animal");
    // Cat cat("my cat");
    // Dog dog("my dog");

    // animal.speak();
    // cat.speak();
    // dog.speak();

    // // 자식 클래스를 부모 클래스의 포인터를 사용해서 캐스팅 시키고 호출하면, 부모 클래스인 줄 앎.
    // Animal* ptr_animal1 = &cat;
    // Animal* ptr_animal2 = &dog;

    // ptr_animal1->speak();
    // ptr_animal2->speak();

    Cat cats[] = {Cat("cat1"),
                  Cat("cat2"),
                  Cat("cat3"),
                  Cat("cat4"),
                  Cat("cat5")};

    Dog dogs[] = {Dog("dog1"), Dog("dog2")};

    // for문을 여러 개 돌려야 하는 번거로움이 있음
    for (int i = 0; i < 5; ++i)
        cats[i].speak();

    for (int i = 0; i < 2; ++i)
        dogs[i].speak();


    // 자식 클래스의 객체를 부모 클래스의 포인터에 넣고 형변환 해서 한꺼번에 사용할 수 있음
    Animal *my_animals[] = {&cats[0], &cats[1], &cats[2], &cats[3], &cats[4],
                            &dogs[0], &dogs[1]};

    for (int i = 0; i < 7; ++i)
        my_animals[i]->speak();

    return 0;
}