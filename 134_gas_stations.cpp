#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(const vector<int>& gas, const vector<int>& costs) 
{
    int total_tank = 0;
    int from_start_tank = 0;
    int start = 0;

    for(int i = 0; i < gas.size(); ++i)
    {
        total_tank += gas[i] - costs[i];
        from_start_tank += gas[i] - costs[i];

        if(from_start_tank < 0)
        {
            from_start_tank = 0;
            start = i+1;
        }
    }

    return (total_tank < 0) ? -1 : start;
}

void test(const vector<int>& gas, const vector<int>& costs)
{
    std::cout << " can complete from: " << canCompleteCircuit(gas, costs) << '\n';
}

int main(int argc, char** argv)
{
    test({1,2,3,4,5}, {3,4,5,1,2}); // 3
    test({2,3,4}, {3,4,3}); // -1
    test({3,3,4}, {3,4,4}); // -1
    test({3,1,1}, {1,2,2}); 

    return 0;
}