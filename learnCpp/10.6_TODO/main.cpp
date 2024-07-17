#include "Worker.h"

/*
    - 의존: Depends-on, 관계가 약하다
    - 관계의 형태: 필요할때만 사용, 용도 외엔 서로 무관 (Worker.cpp 에서 Timer class 사용)
    - 다른 클래스에도 속할 수 있는가? YES (Timer class 다른 곳에서 모두 사용 가능)
    - 멤버의 존재를 클래스가 관리? YES, 일시적으로 사용, 멤버로 들어가지도 않음
    - 방향성: 단방향
*/


int main()
{
    Worker().doSomething();
    return 0;
}