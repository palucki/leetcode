#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void print(const std::vector<int>& v)
{
    for(const auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

int minSubArrayLen(int target, vector<int>& nums)
{
    int current_sum = 0;
    int min_size = 999999;
    int left = 0;

    for(int i = 0; i < nums.size(); ++i)
    {
        current_sum += nums[i];

        while(current_sum >= target && i >= left)
        {
            min_size = std::min(min_size, i - left + 1);
            current_sum -= nums[left];
            left++;
        }
    }

    return min_size == 999999 ? 0 : min_size;   
}

void test(int target, vector<int>& nums)
{
    print(nums);
    std::cout << "Res " << minSubArrayLen(target, nums) << '\n';
}

int main(int argc, char** argv)
{
    {
        auto n = std::vector<int>{2,3,1,2,4,3};
        test(7, n);
    }

    {
        auto n = std::vector<int>{1, 1, 2, 7};
        test(7, n);
    }

    {
        auto n = std::vector<int>{7, 1, 6};
        test(7, n);
    }

    {
        auto n = std::vector<int>{7};
        test(7, n);
    }

    {
        auto n = std::vector<int>{1,4,4};
        test(4, n);
    }

    {
        auto n = std::vector<int>{1,1,1,1,1,1,1,1};
        test(11, n);
    }

    return 0;
}