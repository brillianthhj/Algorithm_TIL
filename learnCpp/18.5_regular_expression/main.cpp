#include <iostream>
#include <regex>
#include <string>


/*
    - regular expression : 레즉스
*/

int main()
{
    // std::regex re("\\d+");               // \d : is number?
    // std::regex re("[[:digit:]]{3}");     // \d == [:digit:], [ ... ] : ... is ok, {3} : set number
    // std::regex re("[A-Z]+");
    // std::regex re("[A-Z]{1,5}");         // from A to Z, number from 1 to 5
    // std::regex re("([0-9]{1})([-]?)([0-9]{1,4})");  // () : grouping, [-]? : - is optional

    // exercise: email format
    std::regex re("^[a-zA-Z0-9+-_\\.]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");

    std::string str;

    while (true)
    {
        std::getline(std::cin, str);

        if (std::regex_match(str, re))
            std::cout << "Match" << std::endl;
        else
            std::cout << "No match" << std::endl;

        // print matches
        {
            auto begin = std::sregex_iterator(str.begin(), str.end(), re);
            auto end = std::sregex_iterator();
            for (auto itr = begin; itr !=end; ++itr)
            {
                std::smatch match = *itr;
                std::cout << match.str() << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}