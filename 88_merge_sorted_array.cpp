#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int pos = nums1.size() - 1; //current pos
    int i = m-1;
    int j = n-1;

    while(j >= 0)
    {
        if(i >= 0 && nums1[i] > nums2[j])
        {
            nums1[pos--] = nums1[i--];
        }
        else 
        {
            nums1[pos--] = nums2[j--];
        }
    }
}

int main(int argc, char** argv)
{
    {
        std::vector<int> num1{1,2,3,0,0,0};
        std::vector<int> num2{2,5,6};
        merge(num1, 3, num2, 3);

        std::cout << "After merge: ";
        for(const auto& e : num1)
        {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }

    {
        std::vector<int> num1{1};
        std::vector<int> num2{};
        merge(num1, 1, num2, 0);

        std::cout << "After merge: ";
        for(const auto& e : num1)
        {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }

    {
        std::vector<int> num1{0};
        std::vector<int> num2{1};
        merge(num1, 0, num2, 1);

        std::cout << "After merge: ";
        for(const auto& e : num1)
        {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }

    {
        std::vector<int> num1{2,0};
        std::vector<int> num2{1};
        merge(num1, 1, num2, 1);

        std::cout << "After merge: ";
        for(const auto& e : num1)
        {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }

    {
        std::vector<int> num1{0,0,0,0,0};
        std::vector<int> num2{1,2,3,4,5};
        merge(num1, 0, num2, 5);

        std::cout << "After merge: ";
        for(const auto& e : num1)
        {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }

    return 0;
}