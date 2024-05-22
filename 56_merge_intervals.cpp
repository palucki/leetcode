#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<vector<int>> result;
    
    std::sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
        return lhs[0] < rhs[0];
    });

    vector<int> last_interval{intervals[0]};
    for(int i = 1; i < intervals.size(); ++i)
    {
        int p_x = last_interval[0];
        int c_x = intervals[i][0];
        int p_y = last_interval[1];
        int c_y = intervals[i][1];

        if(c_x > p_y)
        {
            result.push_back(last_interval);
            last_interval[0] = c_x;
            last_interval[1] = c_y;
        }
        else if(c_x <= p_y && c_y > p_y)
        {
            last_interval[1] = c_y;
        }
    }

    result.push_back(last_interval);

    return result;
}

void print(const std::vector<int>& v)
{
    for(const auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << "| ";
}

void test(vector<vector<int>> intervals)
{
    for(auto v : intervals)
    {
        print(v);
    }
    std::cout << '\n';

    const auto res = merge(intervals);
    std::cout << "Res:\n";

    for(auto v : res)
    {
        print(v);
    }
    std::cout << '\n';
}

int main(int argc, char** argv)
{
    {
        auto n = std::vector<std::vector<int>>{{1,3}, {2,6}, {8,10}, {15,18}};
        test(n);
    }

    {
        auto n = std::vector<std::vector<int>>{{1,4}, {4,5}};
        test(n);
    }

    return 0;
}