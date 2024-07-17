#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"
#include <streambuf>

/*
    - 이동 생성자와 이동 대입
*/

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000000));

    return res;
}



int main()
{
    std::streambuf* orig_buf = std::cout.rdbuf();
    // cout.rdbuf(NULL);    // disconnect cout from buffer

    Timer timer;

    {
        AutoPtr<Resource> main_res;
        main_res = generateResource();
    }

    std::cout.rdbuf(orig_buf);
    // std::cout << timer.elapsed() << std::endl;
    timer.elapsed();

    return 0;
}