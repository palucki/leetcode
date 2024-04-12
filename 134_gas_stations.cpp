#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(const vector<int>& gas, const vector<int>& costs) 
{
    if(gas.size() != costs.size())
    {
        return -1;
    }

    int tank = 0;
    bool tank_ok = false;
    int lowest_tank = 0;
    int lowest_tank_index = 0;

    for(int i = 0; i < gas.size(); ++i)
    {
        tank += gas[i] - costs[i];

        if(tank >= 0) tank_ok = true;

        if(tank < lowest_tank)
        {
            lowest_tank_index = i+1;
            lowest_tank = tank;
        } 
    }

    std::cout << "Tank: " << tank << " ok: " << tank_ok;
    std::cout << " lowest tank: " << lowest_tank << " at: " << lowest_tank_index << '\n';

    if(tank_ok)
    {
        int final_tank = 0;
        for(int i = 0; i < gas.size(); ++i)
        {
            int pos = (i + lowest_tank_index) % gas.size();
            // std::cout << pos << "->";
            
            final_tank += gas[pos] - costs[pos];
            if(final_tank < 0)
            {
                return -1;
            }
        }
    }
    else
    {
        return -1;
    }

    return lowest_tank_index;
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