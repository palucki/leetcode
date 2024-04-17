#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void rotate(vector<int>& nums, int k) 
// {
//     k = k % nums.size();

//     const auto get_new_pos = [&nums](const int k, const int old_pos)
//     {
//         return (old_pos + k) % nums.size();
//     };

//     // to start with
//     int new_index = 0;
//     int value = nums[(nums.size() - k) % nums.size()];

//     std::cout << "new index = " << new_index << " put value " << value << '\n';

//     for(int n = 0; n < nums.size(); ++n)
//     {
//         std::cout << "use val = " << value << " at index " << new_index << " and remember old val = " << nums[new_index] << '\n';

//         int tmp = nums[new_index];
//         nums[new_index] = value;
//         value = tmp;
//         new_index = get_new_pos(k, new_index);
//     }
// }

void rotate(vector<int>& nums, int k) 
{
    k = k % nums.size();
    //it turns out it is enough to reverse array in a smart way to obtain the rotation result

    // first reverse whole array
    std::reverse(nums.begin(), nums.end());

    // next reverse separated arrays, from 0 to k-1, from k to end
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

void print(const std::vector<int>& v)
{
    for(const auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

void test(std::vector<int> nums, int k)
{
    std::cout << "before:\n";
    print(nums);
    rotate(nums,k);
    
    std::cout << "after rotating by " << k << " right:\n";
    print(nums);
}

int main(int argc, char** argv)
{
    test({1, 2, 3, 4}, 2);
    test({1,2,3}, 6);
    test({1,2,3,4,5,6,7}, 3);
    test({1,2,3,4}, 2);
    test({-1,-100,3,99}, 2);

    return 0;
}