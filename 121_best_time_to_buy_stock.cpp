#include <iostream>
#include <vector>

using namespace std;

// single pass
int maxProfit(vector<int>& prices) 
{
    int max_profit = 0;
    int min = prices[0];
    
    for(int i = 1; i < prices.size(); ++i)
    {
        max_profit = std::max(max_profit, prices[i] - min);
        min = std::min(min, prices[i]);
    }

    return max_profit;
}

void test(std::vector<int> nums)
{
    const auto k = maxProfit(nums);
    std::cout << "k = " << k << " vec = ";
    for(const auto& e : nums)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

int main(int argc, char** argv)
{
    test({7,1,5,3,6,4});
    test({7,6,4,3,1});
    test({2,8,1,4});

    return 0;
}