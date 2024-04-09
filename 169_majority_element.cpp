#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(const vector<int>& nums) 
{
    std::unordered_map<int, int> counter;
    
    for(const auto& n : nums)
    {
        counter[n]++;
    }

    for (const auto& [key,val] : counter) 
    {  
        if (val > nums.size() / 2)
            return key;   
    } 

    return -1;
}


void test(const std::vector<int>& nums)
{
    std::cout << " majority: " << majorityElement(nums) << '\n';
}

int main(int argc, char** argv)
{
    test({1,1,2});
    return 0;
}