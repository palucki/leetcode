#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

//input is sorted in non-decreasing order
// requirement: constant space used
// array is 1 indexed

vector<int> twoSum(vector<int>& numbers, int target) 
{
    int left = 0;
    int right = numbers.size() - 1;

    // solves if empty, if the same elem at the middle 
    while(left < right)
    {
        const auto sum = numbers[left] + numbers[right];
        if(sum == target)
            return {left+1, right+1};
        else if (sum < target)
            left++;
        else
            right--;
    }

    return {0, 0};
}

void test(vector<int> nums, int target)
{
    const auto res = twoSum(nums, target);
    std::cout << "indices " << res[0] << "," << res[1] << '\n';
}

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    test({2,7,11,15}, 9);
    test({2,3,4}, 6);
    test({-1,0}, -1);

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}
