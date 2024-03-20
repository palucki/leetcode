#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }

    int pos = 1;
    int val = nums[0];
    for(int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] != val)
        {
            val = nums[pos] = nums[i];
            pos++;
        }
    }

    return pos;
}

void test(std::vector<int> nums)
{
    const auto k = removeDuplicates(nums);
    std::cout << "k = " << k << " vec = ";
    for(const auto& e : nums)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

int main(int argc, char** argv)
{
    test({1,1,2});
    test({0,0,1,1,1,2,2,3,3,4});
    // test({3,2,2,3}, 2);
    // test({1}, 2);
    // test({0,1,2,2,3,0,4,2}, 2);

    return 0;
}