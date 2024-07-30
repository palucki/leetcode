#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    std::unordered_map<std::string, std::vector<std::string>> master_map;
    for(auto i = 0; i < strs.size(); ++i)
    {
        auto s = strs[i];
        std::sort(s.begin(), s.end());

        master_map[s].push_back(strs[i]);
    }

    vector<vector<string>> result;
    for(const auto& [key, value] : master_map)
    {
        std::vector<string> vec;
        for(const auto& s : value)
        {
            vec.push_back(s);
        }
        result.push_back(vec);
    }

    return result;
}

void test(vector<string> strs)
{
    for(const auto& vs : groupAnagrams(strs))
    {
        std::cout << "[ ";
        for(const auto& s : vs)
        {
            std::cout << s << " ";
        }
        std::cout << "]\n";
    }
}

int main()
{
    test({"eat","tea","tan","ate","nat","bat"});
    test({""});
    test({"a"});

    return 0;
}