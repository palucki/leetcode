#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums) 
{
    std::vector<bool> can_reach(nums.size(), false);

    can_reach[0] = true;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(!can_reach[i])
        {
            break;
        }

        int num = nums[i];
        for(int j = 0; j <= num && j < nums.size(); ++j)
        {
            // std::cout << "from " << i << " can reach " << j+i << '\n';
            can_reach[j+i] = true;
        }
    }

    return can_reach[can_reach.size() - 1];
}

void print(const std::vector<int>& v)
{
    for(const auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

void test(std::vector<int> nums)
{
    print(nums);
    std::cout << " can jump to end: " << canJump(nums) << '\n';
}

int main(int argc, char** argv)
{
    test({2,3,1,1,4});
    test({3,2,1,0,4});

    return 0;
}