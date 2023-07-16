#include <iostream>
/*
Question link: https://leetcode.com/problems/reverse-integer/description/

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/


class Solution {
public:
    int reverse(int x) {
        int answer = 0;
        while(x) {
            if (answer > INT32_MAX / 10 || answer < INT32_MIN / 10) {return 0;}
            answer = answer * 10 + x % 10;
            x /= 10; 
        }
        return answer;   
    }
};

int main()
{
    Solution s;
    int question = 1534236469;
    int answer = s.reverse(question);
    std::cout << "The answer is : " << answer << std::endl;
    return 0;   
};