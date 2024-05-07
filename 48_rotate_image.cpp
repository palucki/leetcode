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

void transpose(vector<vector<int>>& matrix)
{
    const auto N = matrix.size();
    for(int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseRows(vector<vector<int>>& matrix)
{
    const auto N = matrix.size();
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N / 2; ++j)
        {
            std::swap(matrix[i][j], matrix[i][N - 1 - j]);
        }
    }
}

void rotate(vector<vector<int>>& matrix) 
{
    transpose(matrix);
    reverseRows(matrix);
}


void test(vector<vector<int>>& board)
{
    print(board);
    std::cout << "Rotated:\n";
    rotate(board);
    print(board);
}

int main(int argc, char** argv)
{
    {
        auto board = std::vector<std::vector<int>>{
            {1,2,3},{4,5,6},{7,8,9}
        };

        test(board);
    }

    // {
    //     auto board = std::vector<std::vector<int>>{
    //         {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    //     };

    //     test(board);
    // }

    return 0;
}