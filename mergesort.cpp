#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> lhs, std::vector<int> rhs)
{
    std::vector<int> result;

    int l=0, r=0;

    while(true)
    {
        if(l == lhs.size() && r == rhs.size())
        {
            break;
        }

        if(l == lhs.size())
        {
            result.push_back(rhs[r]);
            r++;
            continue;
        }

        if(r == rhs.size())
        {
            result.push_back(lhs[l]);
            l++;
            continue;
        }

        if(lhs[l] < rhs[r])
        {
            result.push_back(lhs[l]);
            l++;
        }
        else
        {
            result.push_back(rhs[r]);
            r++;
        }
    }

    return result;
}

std::vector<int> mergesort(std::vector<int> data)
{
    if(data.size() <= 1)
    {
        return data;
    }

    const auto size = data.size();
    const std::vector<int> left{data.begin(), data.begin() + size/2};
    const std::vector<int> right{data.begin() + size/2, data.end()};

    std::cout << "Left\n";
    for(const auto e : left)
    {
        std::cout << e << " ";
    }

    std::cout << '\n';
    std::cout << "Right\n";
    for(const auto e : right)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
    
    return merge(mergesort(left), mergesort(right));
}

int main(int argc, char** argv)
{
    const auto result = mergesort({2,1,6,8,12,5,1,-1,0,7});

    std::cout << "Result\n";
    for(const auto e : result)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';

    return 0;
}