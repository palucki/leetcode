#include <iostream>
#include <sstream>

using namespace std;

int lengthOfLastWord(string s) 
{
    if(s.empty())
    {
        return 0;
    }

    int i = s.size() - 1;
    int length = 0;

    while(i >= 0)
    {
        if(s[i] != ' ')
        {
            length++;
        }
        else if(length > 0)
        {
            return length;
        }

        i--;
    }

    return length;
}

void test(const string& str)
{
    std::cout << "str: " << str << " length of last word: " << lengthOfLastWord(str) << '\n';
}

int main(int argc, char** argv)
{
    test("abc");
    test("Hello World");
    test("   fly me   to   the moon  ");
    test("luffy is still joyboy");

    return 0;
}