#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <tuple>

using namespace std;

void print(const std::vector<int>& v)
{
    for(const auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << '\n';
}

void print(const vector<vector<int>>& board)
{
    for(const auto& r : board)
    {
        for(const auto& e : r)
        {
            std::cout << e << " ";
        }
        std::cout << '\n';
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    std::vector<int> output;

    int minR = 0;
    int maxR = matrix.size() - 1;
    int minC = 0;
    int maxC = matrix[0].size() - 1;

    // std::cout << "minR " << minR << " maxR " << maxR << " minC " << minC << " maxC " << maxC << '\n';

    while(true)
    {
        for(int i = minR, j = minC ; j <= maxC; ++j)
        {
            output.push_back(matrix[i][j]);
        }
        minR++;

        if(minR > maxR || minC > maxC) break;

        std::cout << "minR " << minR << " maxR " << maxR << " minC " << minC << " maxC " << maxC << '\n';
        for(int i = minR, j = maxC; i <= maxR; ++i)
        {
            output.push_back(matrix[i][j]);
        }
        maxC--;

        if(minR > maxR || minC > maxC) break;
        
        for(int i = maxR, j = maxC; j >= minC; --j)
        {
            output.push_back(matrix[i][j]);
        }
        maxR--;

        if(minR > maxR || minC > maxC) break;

        for(int i = maxR, j = minC; i >= minR; --i)
        {
            output.push_back(matrix[i][j]);
        }
        minC++;

        if(minR > maxR || minC > maxC) break;
    }

    return output;
}


void test(vector<vector<int>>& board)
{
    print(board);
    std::cout << "Spiral: ";
    print(spiralOrder(board));
}

int main(int argc, char** argv)
{
    {
        auto board = std::vector<std::vector<int>>{
            {1,2,3},{4,5,6},{7,8,9}
        };

        test(board);
    }

    {
        auto board = std::vector<std::vector<int>>{
            {1,2,3,4},{5,6,7,8},{9,10,11,12}
        };

        test(board);
    }

    return 0;
}