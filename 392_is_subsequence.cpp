#include <iostream>
#include <vector>

using namespace std;
    
bool isSubsequence(string s, string t) 
{
    if(s.empty())
    {
        return true;
    }

    if(t.empty()) // and !s.empty()
    {
        return false;
    }

    int s_i = 0, t_i = 0;

    while(s_i < s.size() && t_i < t.size())
    {
        if(s[s_i] == t[t_i])
        {
            s_i++;
        }

        t_i++;
    }

    return s_i >= s.size();
}

void test(std::string s, std::string t)
{
    std::cout << s << " is subsequence of " << t << ": " << isSubsequence(s, t) << '\n';
}

int main(int argc, char** argv)
{
    std::cout << "Start\n";
    test("abc", "ahbgdc");
    test("axc", "ahbgdc");

    return 0;
}