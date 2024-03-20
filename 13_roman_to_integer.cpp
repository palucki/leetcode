#include <iostream>
#include <vector>

using namespace std;

int romanToInt(string s) 
{
    const auto rti = [](char r)
    {
        switch(r)
        {
            case 'I': return 1; 
            case 'V': return 5; 
            case 'X': return 10; 
            case 'L': return 50; 
            case 'C': return 100; 
            case 'D': return 500; 
            case 'M': return 1000; 
        }

        return 0;
    };

    int result = rti(s[0]);
    for(int i = 1; i < s.size(); ++i)
    {
        auto val = rti(s[i]);
        if((val == 5 || val == 10) && s[i-1] == 'I') val -= 2 * rti(s[i-1]);
        if((val == 50 || val == 100) && s[i-1] == 'X') val -= 2 * rti(s[i-1]);
        if((val == 500 || val == 1000) && s[i-1] == 'C') val -= 2 * rti(s[i-1]);
        
        result += val;
    }

    return result;
}

void test(std::string str)
{
    const auto k = romanToInt(str);
    std::cout << "k = " << k << " str = " << str << '\n';
}

int main(int argc, char** argv)
{
    test("III");
    test("IV");
    test("VI");
    test("IX");
    test("I");
    test("XXXIV");
    test("LVIII");
    test("MCMXCIV");

    return 0;
}