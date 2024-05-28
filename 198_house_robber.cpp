#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int rob(vector<int>& nums) 
{
    bool used_last = true;

    for(int i = 1; i < nums.size(); ++i)
    {
        auto outcome_with_current = nums[i];
        if(i-2 >= 0) outcome_with_current += nums[i-2];
        
        const auto last_outcome = nums[i-1];

        if(outcome_with_current > last_outcome) used_last = true;
        else used_last = false;

        nums[i] = std::max(last_outcome, outcome_with_current);
    }

    return std::max(nums[0], nums[nums.size() - 1]);
}

void test(vector<int> nums)
{
    std::cout << "robber's booty " << rob(nums) << '\n';
}

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    // test({1,2,3,1});
    // test({2, 7, 9, 3, 1});
    // test({1,9,1,1,2});
    test({2,1,1,2});

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}
