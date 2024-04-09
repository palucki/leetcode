#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// boyer-moore voting algorithm
int majorityElement(const vector<int>& nums) 
{
    int counter = 0;
    int candidate = 0;

    for(const auto& n : nums)
    {
        if (counter == 0)
        {
            // counter = 1;
            candidate = n;
        }

        if (n != candidate)
        {
            counter--;
        }
        else 
        {
            counter++;
        }
    }

    return candidate;
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