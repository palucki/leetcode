#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) 
{
    std::unordered_set<int> elems{nums.begin(), nums.end()};
    int longest_seq = 0;

    for(auto it = elems.begin(); it != elems.end(); ++it)
    {
        int element = *it;
        int current_seq = 1;
        
        // check if start of a sequence
        if(elems.find(element-1) == elems.end())
        {
            while(elems.find(++element) != elems.end())
            {
                current_seq++;
            }
        }

        longest_seq = std::max(longest_seq, current_seq);
    }

    return longest_seq;
}

void test(vector<int> nums)
{
    std::cout << "longestConsecutive " << longestConsecutive(nums) << '\n';
}

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    test({100, 4, 200, 1, 3, 2});
    test({0,3,7,2,5,8,4,6,0,1});

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}