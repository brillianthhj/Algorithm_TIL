#include <iostream>
#include <string>
using namespace std;

/*
 * Question link: https://leetcode.com/problems/integer-to-roman/description/
*/

class Solution {
public:
    string intToRoman(int num) {
        // hash table implementation
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hund[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thou[] = {"", "M", "MM", "MMM"};

        return thou[num / 1000] + hund[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};

int main()
{
    Solution s;
    int num = 1994;
    string answer = s.intToRoman(num);
    cout << "The answer is : " << answer << endl;
    return 0;

}