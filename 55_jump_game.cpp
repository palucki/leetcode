#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

bool canJumpRecursively(vector<int>& nums, int i, std::unordered_map<int, bool>& memo)
{
    // std::cout << "At " << i << " memo size " << memo.size() << '\n';
    if (i < 0 || i > nums.size() - 1)
    {
        memo[i] = false;
        return memo[i];
    } 

    if (i == nums.size() - 1)
    {
        memo[i] = true;
        return true;
    }
    
    if(memo.find(i) != memo.end())
    {
        // std::cout << "Return memo\n";
        return memo[i];
    }

    int val = nums[i];

    for(int j = 1; j <= val; j++)
    {
        int jumps_to = i + j;
        if(canJumpRecursively(nums, jumps_to, memo))
        {
            memo[i] = true;
            return memo[i];
        }
    }

    memo[i] = false;
    return memo[i];
}

bool canJumpRecursively(vector<int>& nums) 
{
    std::unordered_map<int, bool> memo;
    return canJumpRecursively(nums, 0, memo);
}

bool canJumpTabulation(vector<int>& nums) 
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
        for(int j = 0; j <= num && j+i < nums.size(); ++j)
        {
            // std::cout << "from " << i << " can reach " << j+i << '\n';
            can_reach[j+i] = true;
        }
    }

    return can_reach[can_reach.size() - 1];
}

bool canJump(vector<int>& nums) 
{
    int max_reach = 0;

    for(int i = 0; i < nums.size(); ++i)
    {
        if(max_reach < i) return false;

        max_reach = std::max(max_reach, i + nums[i]);
    }

    return true;
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
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    test({2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6});

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}