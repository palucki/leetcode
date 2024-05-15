#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    std::size_t longest = 0;
    std::unordered_set<char> already_in_substr;
    for(int i = 0; i < s.size(); ++i)
    {
        // i - currently visited "mid" element
        already_in_substr.clear();
        already_in_substr.insert(s[i]);

        int l = i-1;
        while(l > 0 && already_in_substr.find(s[l]) == already_in_substr.end())
        {
            already_in_substr.insert(s[l--]);
        }

        int r = i+1;
        while(r < s.size() && already_in_substr.find(s[r]) == already_in_substr.end())
        {
            already_in_substr.insert(s[r++]);
        }

        // at this point already_in_substr should have only unique characters and its size should be equal to... 
        longest = std::max(longest, already_in_substr.size());
        // std::cout << "already in substr " << already_in_substr.size() << " r = " << r << " l = " << l << '\n'; 
    }

    return longest;
}

void test(const string& str)
{
    int res = lengthOfLongestSubstring(str);
    std::cout << "str: " << str << " length of longest substr: " << res << '\n';
}

int main(int argc, char** argv)
{
    test("abcabcbb");
    test("bbbbb");
    test("pwwkew");
    test(" ");

    return 0;
}