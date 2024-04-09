#include <iostream>
#include <sstream>

using namespace std;

// 1 brute force
// 2 optimize for in place
string reverseWords(string s)
{
    std::string result;

    std::stringstream ss{s};
    std::string tmp;
    while(ss >> tmp)
    {
        // std::cout << "{" << tmp << "}" << '\n';
        if(result.empty())
        {
            result = tmp;
        }
        else
        {
            result.insert(0, tmp + " ");
        }
    }

    return result;
}

// reverses in place, but does not remove whitespaces
string reverseWordsInPlace(string s)
{
    // first swap - words swapped, but reversed 
    // e.g. hello world -> dlrow olleh
    for(int i = 0; i < s.length() / 2; ++i)
    {
        std::swap(s[i], s[s.length()-i-1]);
    }

    std::cout << "First swap: " << s << '\n';

    // second swap -> words correctly swapped 
    // e.g dlrow olleh -> world hello
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == ' ')
        {
            continue;
        }

        // find j -> index of first whitespace
        int j = i;
        while(j < s.length() && s[j] != ' ') ++j;

        std::cout << "swapping between " << i << " and " << j << '\n';
        
        //swap everything between i and j
        for(int k = 0; k < (j - i) / 2; ++k)
        {
            std::cout << k << " and " << j-k-1 << '\n';
            std::swap(s[i+k], s[j-1-k]);
        }

        i = j;
    }

    return s;
}

void test(const string& str)
{
    std::cout << str << " reversed: " << reverseWords(str) << '\n';
}

int main(int argc, char** argv)
{
    test("the sky is blue");
    test("  hello world  ");
    test("a good   example");

    return 0;
}