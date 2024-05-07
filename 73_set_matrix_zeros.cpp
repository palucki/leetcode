#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <tuple>

using namespace std;

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

void setZeroes(vector<vector<int>>& matrix) 
{
    std::vector<bool> rows_to_zero(matrix.size(), false);
    std::vector<bool> cols_to_zero(matrix[0].size(), false);

    for(int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                rows_to_zero[i] = true;
                cols_to_zero[j] = true;
            }
        }
    }

    for(int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0; j < matrix[0].size(); ++j)
        {
            if(rows_to_zero[i] || cols_to_zero[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void test(vector<vector<int>>& board)
{
    print(board);
    std::cout << "zeros\n";
    setZeroes(board);
    print(board);
}

int main(int argc, char** argv)
{
    {
        auto board = std::vector<std::vector<int>>{
            {1,2,3},{4,0,6},{7,8,9}
        };

        test(board);
    }

    {
        auto board = std::vector<std::vector<int>>{
            {0,1,2,0},{3,4,5,2},{1,3,1,5}
        };

        test(board);
    }

    return 0;
}