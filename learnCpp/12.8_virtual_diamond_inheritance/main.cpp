#include <iostream>

/*
    - 가상 기본 클래스
    - 다이아몬드 상속에서는 맨 아래 자식 클래스가 맨 위 부모 클래스를 호출할 때, 중간 상속 클래스가 2개이기 때문에,
     부모 클래스가 2개가 되어 호출될 수 있음
    - 이것을 방지하기 위해, 중간 자식 클래스들은 부모를 상속할 때 virtual 을 표기, 맨 아래 자식 클래스는 생성자에서
     부모 클래스 초기화 필요
*/

class PoweredDevice
{
public:
    int m_i;

    PoweredDevice(int power)
        : m_i(power)
    {
        std::cout << "PoweredDevice : " << power << "\n";
    }
};

class Scanner : virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power)
    {
        std::cout << "Scanner : " << scanner << "\n";
    }
};

class Printer : virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power)
    {
        std::cout << "Printer : " << printer << "\n";
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
    {
        std::cout << "Copier called" << std::endl;
    }
};

int main()
{
    Copier cop(1, 2, 3);

    // std::cout << &cop.Scanner::PoweredDevice::m_i << std::endl;
    // std::cout << &cop.Printer::PoweredDevice::m_i << std::endl;
    std::cout << &(static_cast<Scanner&>(cop).PoweredDevice::m_i) << std::endl;
    std::cout << &(static_cast<Printer&>(cop).PoweredDevice::m_i) << std::endl;
    /*
    Scanner* scannerPtr = &cop;
    Printer* printerPtr = &cop;

    std::cout << &(scannerPtr->PoweredDevice::m_i) << std::endl;
    std::cout << &(printerPtr->PoweredDevice::m_i) << std::endl;
    */

    return 0;
}