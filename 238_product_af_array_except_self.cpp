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

vector<int> productExceptSelf(vector<int>& nums)
{
    std::vector<int> result(nums.size(), 1);

    //at least 2 elements guaranteed
    if(nums.size() == 2)
    {
        return std::vector<int>{nums[1], nums[0]};
    }

    int val = 1;
    // std::cout << "val = " << val << '\n';

    for(int i = 1; i < nums.size(); ++i)
    {
        // std::cout << "i = " << i << " val = " << val << " nums[i-1] = " << nums[i-1] << '\n';
        val = result[i] = nums[i-1] * val;
    }

    // std::cout << "L: ";
    // print(result);

    val = 1;
    for(int i = nums.size() - 2; i >= 0; --i)
    {
        val = nums[i+1] * val;
        result[i] = result[i] * val;
    }

    return result;
}

void test(std::vector<int> nums)
{
    print(nums);
    std::cout << "results:\n";
    print(productExceptSelf(nums));
}

int main(int argc, char** argv)
{
    test({-1,1,1});
    test({-1,1,-1});
    test({0, 1, -1});
    test({1,2,3,4});
    test({-1,1,0,-3,3});
    return 0;
}