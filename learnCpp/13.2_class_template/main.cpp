#include "MyArray.h"

/*
    - 템플릿 클래스의 멤버 함수 정의 및 구현은 헤더파일에 해야함, 구현이 컴파일 타임에 모두 정의돼있어야 하기 때문.
    - 템플릿 구현을 소스 파일로 분리하면 컴파일러가 템플릿 인스턴스를 생성하지 못해 링커 에러가 발생함.
    - MyArray.h와 "MyArray_impl.h or MyArray.inc" 로 선언, 구현부로 나눌수 있긴 함.
    - explicit instantiation : cpp 파일에서 선언할 수 있음, 근데 일일이 T 에 대해 다 선언해야 함
        - ex) template class MyArray<char>;
              template class MyArray<double>; ...
        - ex) template void MyArray<char>::print();
              template void MyArray<double>::print(); ...
*/

int main()
{
    MyArray<double> my_array(10);

    for (int i = 0; i < my_array.getLength(); ++i)
        my_array[i] = i * 2.0;

    my_array.print();

    return 0;
}