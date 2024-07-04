#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) 
{
    std::stack<char> st;

    for(const auto& c : s)
    {
        if (c == '[' || c == '{' || c == '(')
        {
            st.push(c);
        }
        else if(!st.empty() && ((c == ']' && st.top() == '[') ||
                                (c == '}' && st.top() == '{') ||
                                (c == ')' && st.top() == '(')))
        {
            st.pop();
        }
        else 
        {
            return false;
        }
    }

    return st.empty();
}

void test(string s)
{
    std::cout << s  << " is valid: " << isValid(s) << '\n';
}

int main(int argc, char** argv)
{
    // test("()");
    // test("()[]{}");
    // test("(]");
    // test("({([");
    test("){");
    test("(])");

    return 0;
}