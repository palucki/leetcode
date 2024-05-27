#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int climbStairs(int n)
{
    std::unordered_map<int, int> memo;
    std::function<int(int)> climbStairsSolver = [&memo, &climbStairsSolver](int n)
    {
        if(n <= 1) return 1;
        if(n == 2) return 2;

        if(memo.find(n) != memo.end())
        {
            return memo[n];
        }

        memo[n] = climbStairsSolver(n-1) + climbStairsSolver(n-2);

        return memo[n];
    };

    return climbStairsSolver(n);
}

void test(int n)
{
    std::cout << "N = " << n << " possible ways " << climbStairs(n) << '\n';
}

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    test(45);

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}