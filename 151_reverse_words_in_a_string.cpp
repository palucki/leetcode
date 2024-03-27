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