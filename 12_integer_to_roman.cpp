#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string intToRoman(int num) 
{
    std::unordered_map<int, std::string> int_to_roman {
        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
        {5, "V"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {9, "IX"},
        {10, "X"},
        {20, "XX"},
        {30, "XXX"},
        {40, "XL"},
        {50, "L"},
        {60, "LX"},
        {70, "LXX"},
        {80, "LXXX"},
        {90, "XC"},
        {100, "C"},
        {200, "CC"},
        {300, "CCC"},
        {400, "CD"},
        {500, "D"},
        {600, "DC"},
        {700, "DCC"},
        {800, "DCCC"},
        {900, "CM"},
        {1000, "M"},
        {2000, "MM"},
        {3000, "MMM"},
    };

    std::string result;

    int factor = 1;
    while(num > 0)
    {
        const auto val = num % 10;
        result.insert(0, int_to_roman[val * factor]);
        num /= 10;
        factor *= 10;
    }   

    return result;  
}

void test(int k)
{
    const auto str = intToRoman(k);
    std::cout << "k = " << k << " str = " << str << '\n';
}

int main(int argc, char** argv)
{
    test(3);
    test(58);
    test(1994);

    return 0;
}