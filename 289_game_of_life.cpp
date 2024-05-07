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

void gameOfLife(vector<vector<int>>& board) 
{
    auto is_valid = [&board](int i, int j)
    {
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    };

    auto alive_ns = [&board, &is_valid](int row, int col)
    {
        int alive_neighbors = 0;
        for(int i = -1; i < 2; ++i)
        {
            for(int j = -1; j < 2; ++j)
            {
                if (i == 0 && j == 0) continue;

                int candidate_row = row+i;
                int candidate_col = col+j;

                if(is_valid(candidate_row, candidate_col))
                {
                    if(board[candidate_row][candidate_col] % 2 == 1)
                    {
                        alive_neighbors++;
                    }
                }
            }
        }

        return alive_neighbors;        
    };

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            int alive_neighbors = alive_ns(i, j);
            const auto is_alive = board[i][j] % 2 == 1;

            // Any live cell with fewer than two live neighbors dies as if caused by under-population.
            // Any live cell with two or three live neighbors lives on to the next generation.
            // Any live cell with more than three live neighbors dies, as if by over-population.
            // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
            if(!is_alive)
            {
                if(alive_neighbors == 3) board[i][j] = 2;
                else board[i][j] = 0;
            }
            else
            {
                if(alive_neighbors < 2 || alive_neighbors > 3) board[i][j] = 1;
                else board[i][j] = 3;
            }
        }
    }

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(board[i][j] == 0 || board[i][j] == 1) board[i][j] = 0;
            else board[i][j] = 1;
        }
    }
}

void test(vector<vector<int>>& board)
{
    print(board);
    std::cout << "game of life next state\n";
    gameOfLife(board);
    print(board);
}

int main(int argc, char** argv)
{
    std::cout << "Test 1\n";
    {
        auto board = std::vector<std::vector<int>>{
            {0,1,0},{0,0,1}, {1,1,1}, {0,0,0}
        };

        test(board);
    }

    std::cout << "Test 2\n";
    {
        auto board = std::vector<std::vector<int>>{
            {1,1},{1,0}
        };

        test(board);
    }

    std::cout << "Test 3\n";
    {
        auto board = std::vector<std::vector<int>>{
            {1,1},{1,1}
        };

        test(board);
    }

    return 0;
}