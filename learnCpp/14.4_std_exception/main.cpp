#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

/*
    - std::exception 소개
    - std::exception 클래스를 상속 받아서 우리의 custom exception 클래스 만드는 법 확인
    - what() 함수 overriding
*/

class CustomException : public std::exception
{
public:
    // noexcept : 이 안에서는 예외를 던지지 않겠다.
    const char* what() const noexcept override
    {
        return "Custom exception";
    }
};


int main()
{
    try {
        // 기존 STL 기능들 예외처리는 이미 std::exception에서 돼있음
        // std::string s;
        // s.resize(-1);

        // std::exception의 자식 클래스 runtime_error 호출
        // throw std::runtime_error("Bad thing happened");

        // 사용자 정의 Exception 클래스 호출
        throw CustomException();
    }
    // typeid(exception).name() 호출해서 알아낸 특정 예외처리 자식 클래스
    catch (const std::length_error& le)
    {
        std::cout << "length error" << std::endl;
        std::cerr << le.what() << std::endl;

    }
    catch (std::exception& exception) {
        // 예외 타입 출력
        std::cout << typeid(exception).name() << std::endl;
        // 예외 메세지 출력
        std::cerr << exception.what() << std::endl;
    }

    return 0;
}