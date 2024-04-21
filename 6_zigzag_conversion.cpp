#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

string convert(string s, int numRows) 
{
    if (numRows == 1)
        return s;

    string output;
    int factor = 2 * (numRows - 1);

    for(int r = 0; r < numRows; ++r)
    {
        int f1 = (r == 0 || r == numRows - 1) ? factor : (factor - 2*r);
        int f2 = (r == 0 || r == numRows - 1) ? factor : factor - f1;

        // std::cout << "Row " << r << " f1 " << f1 << " f2 " << f2 << '\n';

        int iter = r;
        while (iter < s.size())
        {
            output += s[iter];
            iter += f1;

            if(iter >= s.size())
                continue;

            output += s[iter];
            iter += f2;
        }
    }

    return output;
}

void test(string s, int numRows, string expected)
{
    auto res = convert(s, numRows);
    std::cout << "in: " << s << " out: " << res;
    if(res != expected)
    {
        std::cout << " -> FAIL";
    }
    std::cout << '\n';
}

int main(int argc, char** argv)
{
    test("PAYPALISHIRING", 1, "PAYPALISHIRING");
    test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    test("PAYPALISHIRING", 2, "PYAIHRNAPLSIIG");
    test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    return 0;
}