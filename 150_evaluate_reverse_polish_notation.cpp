#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens) 
{
    if (tokens.empty())
    {
        return 0;
    }

    std::stack<int> s;
    for(const auto& t : tokens)
    {
        if(t == "+")
        {
            int second = s.top();
            s.pop();
            s.top() = s.top() + second;
        }
        else if(t == "-")
        {
            int second = s.top();
            s.pop();
            s.top() = s.top() - second;
        }
        else if(t == "*")
        {
            int second = s.top();
            s.pop();
            s.top() = s.top() * second;
        }
        else if(t == "/")
        {
            int second = s.top();
            s.pop();
            s.top() = s.top() / second;
        }
        else 
        {
            s.push(stoi(t));
        }
    }

    return s.top();
}

void test(vector<string> tokens)
{
    for(const auto t : tokens)
    {
        std::cout << t << ' ';
    }
    std::cout << "result: " << evalRPN(tokens) << '\n';
}

int main(int argc, char** argv)
{
    test({});
    test({"12"});
    test({"-2"});
    test({"2", "3", "+"});
    test({"2", "3", "+", "5", "+"});
    test({"5", "2", "3", "+", "+"});
    test({"5", "2", "3", "+", "+", "7", "1", "+", "+"});
    test({"2", "3", "-"});
    test({"2", "3", "-", "5", "-"});
    test({"2", "3", "*"});
    test({"2", "3", "4", "*", "*"});
    test({"4", "2", "3", "*", "+"});

    std::cout << "Testcases\n";
    test({"2","1","+","3","*"});
    test({"4","13","5","/","+"});
    test({"10","6","9","3","+","-11","*","/","*","17","+","5","+"});

    return 0;
}