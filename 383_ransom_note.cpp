#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_set>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    std::unordered_multiset<char> magazine_letters(magazine.begin(), magazine.end());

    for(const auto& s : ransomNote)
    {
        const auto it = magazine_letters.find(s);
        if(it == magazine_letters.end())
        {
            return false;
        }

        magazine_letters.erase(it);
    }

    return true;
}

void test(string ransomNote, string magazine)
{
    std::cout << "can construct " << ransomNote << " from " << magazine << " " << canConstruct(ransomNote, magazine) << '\n';
}

int main(int argc, char** argv)
{
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    test("a", "b");
    test("a", "ab");
    test("aa", "aab");

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> elapsed = stop - start;
	std::cout << "Elapsed: " << elapsed.count() << " ms" << std::endl;

    return 0;
}