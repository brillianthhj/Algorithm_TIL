#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

/*
    - 예외처리의 기본: 퍼포먼스 측면에서는 느릴 수 있어 큼직하게 사용
        - assert
        - throw, try, catch
    - 예측할 수 없는 일들이 벌어지는 경우 (인터넷 서버: 네트워크 환경, 게임 서버에서 의도치 않은 입력, 행위들)
    - 예외를 throw 할 때, 보내는 자료형과 catch()에서 받는 자료형이 일치하지 않으면 abort (core dumped) error 발생
*/

// int findFirstChar(const char* string, const char ch)
// {
//     for (std::size_t index = 0; index < strlen(string); ++index)
//     {
//         if (string[index] == ch)
//             return index;
//     }

//     return -1;  // no match
// }

// double divide(const int& x, const int& y, bool& success)
// {
//     if (y == 0)
//     {
//         success = false;
//         return 0.0;
//     }

//     success = true;
//     return static_cast<double>(x) / y;
// }

int main()
{
    // bool success;
    // double result = divide(5, 3, success);

    // if (!success)
    //     std::cerr << "An error occured" << std::endl;
    // else
    //     std::cout << "Result is " << result << std::endl;

    // // 흔히 사용되는 패턴
    // std::ifstream input_file("temp.txt");
    // if (!input_file)
    //     std::cerr << "Cannot open file" << std::endl;

    // try, catch, throw
    double x;
    std::cout << "Input value for sqrt : ";
    std::cin >> x;

    try
    {
        if (x < 0.0)
            // string이 아니라면 아래 catch문에서 못받아서 에러가 남
            // throw std::string("Negative input");
            // double이면 integer가 아니므로 형변환 안돼서 Aborted (core dumped) 됨
            throw std::string("hello");

        std::cout << std::sqrt(x) << std::endl;
    }
    catch (int x)
    {
        std::cout << "Catch integer " << x << std::endl;
    }
    catch (double x)
    {
        std::cout << "Catch double " << x << std::endl;
    }
    catch (const char* error_message)
    {
        std::cout << "Char* " << error_message << std::endl;
    }
    catch (std::string error_message)
    {
        // do something to respond
        std::cout << error_message << std::endl;
    }

    return 0;
}