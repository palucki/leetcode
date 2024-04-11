#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    std::string lcp{""};

    int i = 0;
    while(true && strs[0].size() > i)
    {
        // std::cout << "i = " << i << '\n';
        char p = strs[0][i];

        for(int j = 0; j < strs.size(); ++j)
        {
            if(i >= strs[j].size() || strs[j][i] != p)
            {
                return lcp;
            }
        }

        i++;
        lcp += p;
    }

    return lcp;
}

void test(vector<string> strs)
{
    std::cout << " longest common prefix: " << longestCommonPrefix(strs) << '\n';
}

int main(int argc, char** argv)
{
    std::cout << "Start\n";
    test({"flower","flow","flight"});
    test({"dog","racecar","car"});
    test({"car","car","car"});
    test({"car"});
    test({"","",""});

    return 0;
}