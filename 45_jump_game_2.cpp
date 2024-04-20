#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

const int maxval = 100001;
int jumpRecursively(vector<int>& nums, int i, std::vector<int>& memo)
{
    if (i >= nums.size() - 1)
    {
        return 0;
    }
    
    if (memo[i] != maxval)
    {
        return memo[i];
    }

    int min_jumps = maxval;
    for(int j = 1; j <= nums[i]; j++)
    {
        int jumps_to = i + j;
        int jumps_taken = 1 + jumpRecursively(nums, jumps_to, memo);
        min_jumps = std::min(min_jumps, jumps_taken);
    }

    memo[i] = min_jumps;
    return min_jumps;
}

int jump(vector<int>& nums)
{
    std::vector<int> memo(nums.size(), maxval);
    return jumpRecursively(nums, 0, memo);
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
    std::cout << " min jumps: " << jump(nums) << '\n';
}

int main(int argc, char** argv)
{
    // test({2,3,1,1,4}); // 2
    // test({2,3,0,1,4}); // 2
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    // test({5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5});
    test({8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5});

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}