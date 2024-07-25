#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<char>>& grid)
{
    for(const auto& vec : grid)
    {
        for(const auto& p : vec)
        {
            if(p != '0')
                std::cout << p;
            else 
                std::cout << ' ';
        }
        std::cout << '\n';
    }
}

struct Pos {
    int x;
    int y;

     friend ostream& operator<<(ostream& os, const Pos& p);
};

ostream& operator<<(ostream& os, const Pos& p)
{
    os << p.x << ',' << p.y;
    return os;
}

void erase_islands_bfs(vector<vector<char>>& grid, const Pos& start)
{
    std::cout << "erase_islands_bfs at elem (x,y) " << start << '\n';
    std::queue<Pos> to_visit;

    const auto visit_neighbours = [&grid, &to_visit](const Pos& pos)
    {
        for(const auto& n : std::initializer_list<Pos>{{pos.x-1, pos.y}, 
                                                    {pos.x+1, pos.y}, 
                                                    {pos.x, pos.y+1}, 
                                                    {pos.x, pos.y-1}})
        {
            if(n.x >= 0 && n.x < grid[0].size() && n.y >= 0 && n.y < grid.size() && grid[n.y][n.x] == '1')
            {
                grid[n.y][n.x] = '.';
                to_visit.push(n);
            }
        }
    };

    grid[start.y][start.x] = '.';
    visit_neighbours(start);

    while(!to_visit.empty())
    {
        auto pos = to_visit.front();
        to_visit.pop();
        // std::cout << "At elem " << pos << " to visit size " << to_visit.size() << '\n';
        visit_neighbours(pos);        
    }
}

int numIslands(vector<vector<char>>& grid) 
{
    int number_of_islands = 0;

    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == '1')
            {
                number_of_islands++;
                erase_islands_bfs(grid, {j,i});
            }
        }
    }

    return number_of_islands;
}

void test(vector<vector<char>>& map)
{
    print(map);
    int num = numIslands(map);
    print(map);
    std::cout << "number of islands: " << num << '\n';
}

int main()
{
    {
        vector<vector<char>> map{
            {{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},
            {'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},
            {'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},
            {'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},
            {'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
            {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}}
        };  

        test(map);
    }

    {
        vector<vector<char>> map{
            {'0'}
        };  

        test(map);
    }

    {
        vector<vector<char>> map{
            {'1', '0'},
            {'0', '1'},
        };  

        test(map);
    }

    {
        vector<vector<char>> map{
            {'1', '0', '1'},
            {'0', '1', '0'},
        };  

        test(map);
    }
    
    {
        vector<vector<char>> map{
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}   
        };  

        test(map);
    }

    {
        vector<vector<char>> map{
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'} 
        };  

        test(map);
    }

    return 0;
}