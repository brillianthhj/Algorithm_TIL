#include <iostream>

/*
    - 오른쪽 값 참조 (R-value reference)
        - 곧 사라질 애들만 담을 수 있음 (ex: constant 5, int getValue(), ...)
*/

int getResult()
{
    return 100 * 100;
}

void doSomething(const int& lref)
{
    std::cout << "L-value ref" << std::endl;
}

// move 해서 사용해도 된다, move semantics 사용
void doSomething(int&& rref)
{
    std::cout << "R-value ref" << std::endl;
}

int main()
{
    // l value : 메모리를 가짐
    // r value : 숫자 5, 문장이 끝나면 사라짐
    int x = 5;
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    // L-value references

    int& lr1 = x;           // Modifiable l-values
    // int& lr2 = cx;       // Non-modifiable l-values
    // int& lr3 = 5;        // R-values: 애초에 메모리가 없는 건 넣을 수 없음

    const int& lr4 = x;     // Modifiable l-values
    const int& lr5 = cx;    // Non-modifiable l-values
    const int& lr6 = 5;     // R-values

    // R-value references (&& : R-value only)

    // int&& rr1 = x;          // Modifiable l-values
    // int&& rr2 = cx;         // Non-modifiable l-values
    int&& rr3 = 5;          // R-values
    int&& rrr = getResult();    // getResult()가 임시 값이므로 R-values 처럼 활용 가능

    // 이동 시켜도 상관없는 값들을 할당해서 쓰는 것 같음
    std::cout << rr3 << std::endl;
    rr3 = 10;
    std::cout << rr3 << std::endl;

    // x, cx : 다른 곳에서 접근 가능한 메모리 존재하는 변수들은 R-value에 해당될 수 없음!
    // const int&& rr4 = x;    // Modifiable l-values
    // const int&& rr5 = cx;   // Non-modifiable l-values
    const int&& rr6 = 5;    // R-values

    // L/R-value reference parameters
    doSomething(x);
    doSomething(cx);
    doSomething(6);
    doSomething(getResult());

    return 0;
}