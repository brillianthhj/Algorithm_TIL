#include <iostream>

/*
    - 예외처리와 스택 되감기
    - 가장 안쪽에 있는 함수가 예외를 던진다면 스택을 되감아 가면서 어디서 예외를 받을 지 찾게됨
    - throw에 걸맞는 catch 자료형이 나타날 때까지 기존 스택 아래 내용 무시하고 진행
    - catch 자료형이 모두 안맞으면 런타임 에러 발생
    - catch 괄호 안에 ellipsis를 넣으면 어떤 타입이든 다 받아줄 수 있음
    - exception specifier(사실 별필요 없음): 함수 정의/선언 시 뒤에다가 throw(int) 하면, int type exception throw 할 수 있음을 의미
*/

// exception specifier: 예외를 던질 가능성이 있는 함수임을 알려줌
// throw() : () 안에 아무것도 없으면, 예외를 안던질거다 라는 문법
void last() throw(...)
{
    std::cout << "last " << std::endl;
    std::cout << "Throws exception" << std::endl;

    throw -1;
    // throw 'a';

    std::cout << "End last" << std::endl;

}

void third()
{
    std::cout << "third" << std::endl;

    last();

    std::cout << "End third" << std::endl;
}

void second()
{
    std::cout << "second" << std::endl;

    try {
        third();
    } catch (double) {
        std::cerr << "second caught double exception" << std::endl;
    }

    std::cout << "End second" << std::endl;
}

void first()
{
    std::cout << "first" << std::endl;

    try {
        second();
    } catch (int) {
        std::cerr << "first caught int exception" << std::endl;
    }

    std::cout << "End first" << std::endl;
}

int main()
{
    std::cout << "Start" << std::endl;

    try {
        first();
    } catch (int) {
        std::cerr << "main caught int exception" << std::endl;
    }

    // uncaught exceptions

    catch (...) // catch-all handlers
    {
        std::cerr << "main caught ellipses exception" << std::endl;
    }

    std::cout << "End main" << std::endl;

    return 0;
}