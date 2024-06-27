#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    std::unordered_map<int, int> indices; // maps value to index where the value is stored
    for(int i = 0; i < nums.size(); ++i)
    {
        const auto expected_val = target - nums[i];
        if(indices.find(expected_val) != indices.end())
        {
            return {indices[expected_val], i}; 
        }

        indices[nums[i]] = i;
    }

    return {-1, -1};
}

void test(vector<int> nums, int target)
{
    const auto res = twoSum(nums, target);
    std::cout << "indices " << res[0] << "," << res[1] << '\n';
}

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    test({2,7,11,15}, 26);

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}
