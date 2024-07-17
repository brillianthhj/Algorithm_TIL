#include "Calc.h"


int main()
{
    // this를 통해서 자기자신 리턴 : chanining member function
    Calc cal(10);
    cal.add(8).sub(1).mult(2);
    cal.print();

    Calc(10).add(10).sub(1).mult(2).print();

    return 0;
}