#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
    if(s.empty())
    {
        return 0;
    }
    
    std::unordered_map<char, int> already_in_substr;
    already_in_substr.insert({s[0], 1});
    int longest = 1;
    int l = 0;
    
    for(int i = 1; i < s.size(); ++i)
    {
        if(already_in_substr.find(s[i]) != already_in_substr.end())
        {
            // already in the substr, need to move "window" to the elem right to it
            l = std::max(already_in_substr[s[i]], l);
        }

        already_in_substr[s[i]] = i+1;

        longest = std::max(longest, i - l + 1);
        // std::cout << "new longest =  " << longest << " i = " << i << " l = " << l << '\n'; 
    }

    return longest;
}


int lengthOfLongestSubstringSet(string s) 
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
    test("abba");

    return 0;
}