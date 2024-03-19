#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
    int k = 0;
    int end = nums.size() - 1;
    for(int i = 0; i <= end; ++i)
    {
        if(nums[i] != val)
        {
            k++;
            continue;
        }

        while(end > i && nums[end] == val)
        {
            end--;
        }

        if(nums[i] != nums[end])
        {
            std::swap(nums[i], nums[end--]);
            k++;
            continue;
        }
    }

    return k;
}

void test(std::vector<int> nums, int val)
{
    const auto k = removeElement(nums, val);
    std::cout << "k = " << k << " vec = ";
    for(const auto& e : nums)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

int main(int argc, char** argv)
{
    test({1,2,3}, 2);
    test({3,2,2,3}, 2);
    test({1}, 2);
    test({0,1,2,2,3,0,4,2}, 2);

    return 0;
}