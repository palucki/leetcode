#include <iostream>
#include <vector>

using namespace std;
    
bool isPalindrome(string s) 
{
    int left = 0;
    int right = s.size() - 1;

    while(left < right)
    {
        if(!std::isalnum(s[left]))
        {
            left++;
            continue;
        }

        if(!std::isalnum(s[right]))
        {
            right--;
            continue;
        }

        if(std::tolower(s[left]) != std::tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

void test(std::string s)
{
    std::cout << s << " is palidrome: " << isPalindrome(s) << '\n';
}

int main(int argc, char** argv)
{
    std::cout << "Start\n";
    test("A");
    test("A man, a plan, a canal: Panama");
    test("kajak");
    test("race a car");
    test(" ");
    test("  ");
    test("   ");
    test("aa");

    return 0;
}