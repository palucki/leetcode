#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <tuple>

using namespace std;

int binsearch_row(vector<vector<int>>& matrix, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int m = low + (high - low) / 2;
    
    // std::cout << "\nusing l " << low << " m " << m << " h " << high << " target is " << target << '\n';
    int elem_l = matrix[m][0];
    int elem_r = matrix[m][matrix[0].size() - 1];

    if (target < elem_l)
    {
        // std::cout << "Upper\n";
        return binsearch_row(matrix, low, m-1, target);
    }
    else if(target > elem_r)
    {
        // std::cout << "Lower\n";
        return binsearch_row(matrix, m+1, high, target);
    }
    else 
    {
        std::cout << "Row " << m << "!\n";
        return m;
    }

    return -1;
}

int binsearch_col(vector<int>& row, int low, int high, int target)
{
    if (high < low)
    {
        return -1;
    }

    int m = low + (high-low) / 2;
    int elem = row[m];

    if(target < elem)
    {
        return binsearch_col(row, low, m-1, target);
    }
    else if (target > elem)
    {
        return binsearch_col(row, m+1, high, target);
    }
    else 
        return m;

    return -1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    //find row, start at the middle
    auto row = binsearch_row(matrix, 0, matrix.size()-1, target);
    if(row == -1)
    {
        std::cout << "Not found row\n";
        return false;
    }

    auto col = binsearch_col(matrix[row], 0, matrix[0].size()-1, target);
    if(col == -1)
    {
        std::cout << "Not found col\n";
        return false;
    }

    return true;
}

void test(vector<vector<int>>& matrix, int target)
{
    std::cout << "search matrix for target " << target << " " << std::boolalpha << searchMatrix(matrix, target) << '\n';
}

int main(int argc, char** argv)
{
    {
        auto board = std::vector<std::vector<int>>{
            {1,3,5,7},{10,11,16,20},{23,30,34,60}
        };

        test(board, -1);
        test(board, 1);
        test(board, 2);
        test(board, 3);
        test(board, 8);
        test(board, 14);
        test(board, 22);
        test(board, 25);
        test(board, 60);
        test(board, 100);
    }

    return 0;
}