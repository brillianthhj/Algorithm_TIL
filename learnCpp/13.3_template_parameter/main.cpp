#include "MyArray.h"
/*
    - tempate<typename T, "datatype" data> 이런식으로 컴파일 타임에 넣어줄 변수 추가할 수 있음
*/

int main()
{
    // 동적 할당
    // std::vector<double> my_array; my_array.resize(100);
    // MyArray<double> my_array(100);

    // 컴파일 타임 할당, 100을 변수에 할당해서 전달하면 안됨 (i = 100, MyArray<double, i> 안됨)
    MyArray<double, 100> my_array;  // std::array<double, 100>

    for (int i = 0; i < my_array.getLength(); ++i)
        my_array[i] = i * 1.5;

    my_array.print();

    return 0;
}