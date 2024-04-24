#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <tuple>

using namespace std;

void print(const vector<vector<char>>& board)
{
    for(const auto& r : board)
    {
        for(const auto& e : r)
        {
            std::cout << e;
        }
        std::cout << '\n';
    }
}

bool isValidSudoku(vector<vector<char>>& board) 
{
    using set_t = std::set<char>;
    std::array<set_t, 27> sets;

    auto get_set_indices = [](int i, int j) -> std::tuple<int, int, int>
    {
        int grid_factor = 0;

        if(i >= 0 && i < 3) grid_factor = i/3 + j/3;
        if(i >= 3 && i < 6) grid_factor = 2 + i/3 + j/3;
        if(i >= 6 && i < 9) grid_factor = 4 + i/3 + j/3;

        const auto rows_index = i;
        const auto cols_index = 9 + j;
        const auto grid_index = 18 + grid_factor;

        return {rows_index, cols_index, grid_index};
    };

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board.size(); ++j)
        {
            auto set_indices = get_set_indices(i, j);
            // std::cout << "Set indicies " << std::get<0>(set_indices) << " " << std::get<1>(set_indices) << " " << std::get<2>(set_indices) << '\n';

            auto& rows_set = sets[std::get<0>(set_indices)];
            auto& cols_set = sets[std::get<1>(set_indices)];
            auto& grid_set = sets[std::get<2>(set_indices)];

            const auto c = board[i][j];

            if(c == '.') continue;
            
            if(rows_set.find(c) == rows_set.end()) rows_set.insert(c);
            else return false;

            if(cols_set.find(c) == cols_set.end()) cols_set.insert(c);
            else return false;

            if(grid_set.find(c) == grid_set.end()) grid_set.insert(c);
            else return false;
        }
    }

    return true;
}

void test(vector<vector<char>>& board)
{
    print(board);
    const auto valid = isValidSudoku(board);
    std::cout << "is valid sudoku: " << valid << '\n';
}

int main(int argc, char** argv)
{
    {
        auto board = std::vector<std::vector<char>>{
            {'5','3','.','.','7','.','.','.','.'}
            ,{'6','.','.','1','9','5','.','.','.'}
            ,{'.','9','8','.','.','.','.','6','.'}
            ,{'8','.','.','.','6','.','.','.','3'}
            ,{'4','.','.','8','.','3','.','.','1'}
            ,{'7','.','.','.','2','.','.','.','6'}
            ,{'.','6','.','.','.','.','2','8','.'}
            ,{'.','.','.','4','1','9','.','.','5'}
            ,{'.','.','.','.','8','.','.','7','9'}
        };

        test(board);
    }

    {
        auto board = std::vector<std::vector<char>>{
             {'8','3','.','.','7','.','.','.','.'}
            ,{'6','.','.','1','9','5','.','.','.'}
            ,{'.','9','8','.','.','.','.','6','.'}
            ,{'8','.','.','.','6','.','.','.','3'}
            ,{'4','.','.','8','.','3','.','.','1'}
            ,{'7','.','.','.','2','.','.','.','6'}
            ,{'.','6','.','.','.','.','2','8','.'}
            ,{'.','.','.','4','1','9','.','.','5'}
            ,{'.','.','.','.','8','.','.','7','9'}
        };

        test(board);
    }

    return 0;
}