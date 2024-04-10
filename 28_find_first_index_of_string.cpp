#include <iostream>
#include <sstream>

using namespace std;

bool areEqual(const std::string& h, const std::string& n, int offset)
{
    for(int i = 0; i < n.size(); ++i)
    {
        if(i + offset >= h.size())
        {
            return false;
        }

        if(h[i + offset] != n[i])
        {
            return false;
        }
    }

    return true;
}

int strStr(string haystack, string needle) 
{
    const auto are_equal = [&haystack, &needle](int offset) 
    {
        for(int i = 0; i < needle.size(); ++i)
        {
            if(i + offset >= haystack.size())
            {
                return false;
            }

            if(haystack[i + offset] != needle[i])
            {
                return false;
            }
        }

        return true;
    };

    for(int h_i = 0; h_i < haystack.size(); ++h_i)
    {
        if(are_equal(h_i))
        {
            return h_i;
        }
    }

    return -1;   
}

void test(const string& str1, const string& str2)
{
    std::cout << " index of: " << strStr(str1, str2) << '\n';
}

int main(int argc, char** argv)
{
    test("sadbutsad", "sad");  // 0 
    test("sadbutsad", "but");  // 3
    test("leetcode", "leeto"); // -1
    test("mississa", "issi");  // 1
    test("mississa", "issa");  // 4

    return 0;
}