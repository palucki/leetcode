#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int climbStairs(int n)
{
    if(n <= 1) return 1;
    if(n == 2) return 2;
    else return climbStairs(n-1) + climbStairs(n-2);
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