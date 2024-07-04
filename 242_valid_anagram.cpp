#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// time complexity O(n * log n)
bool isAnagramSorting(string s, string t)
{
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    return s == t;
}

bool isAnagramHashMap(string s, string t)
{
    // character / count 
    // compare maps 
    std::unordered_map<char, int> chars_s;
    std::unordered_map<char, int> chars_t;

    for(const auto& c : s)
        chars_s[c]++;

    for(const auto& c : t)
        chars_t[c]++;

    return chars_s == chars_t;
}

bool isAnagram(string s, string t) 
{
    return isAnagramHashMap(s, t);
}

void test(string s, string t)
{
    std::cout << s  << " and " << t << " are anagrams: " << std::boolalpha << isAnagram(s, t) << '\n';
}

int main(int argc, char** argv)
{
    test("anagram", "nagrama");
    test("anagram", "nagaram");
    test("rat", "car");

    return 0;
}