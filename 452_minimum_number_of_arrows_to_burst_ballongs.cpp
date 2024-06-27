#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(const vector<vector<int>>& points)
{
    for(const auto& p : points)
    {
        std::cout << "[" << p[0] << "," << p[1] << "] ";
    }
    std::cout << '\n';
}

int findMinArrowShots(vector<vector<int>>& points) 
{
    std::sort(points.begin(), points.end());
    // std::cout << '\n';
    // print(points);

    // marks current range for single arrow
    int high = points[0][1];
    int arrows = 1;

    for(int i = 1; i < points.size(); ++i)
    {
        // std::cout << "high " << high << " current " << points[i][0] << "," << points[i][1] << '\n';
        
        // check if have common part -> if so, then new range is formed by former points[i][0] and high
        if(points[i][0] <= high)
        {
            // we can reuse the same arrow
            high = std::min(high, points[i][1]);
        }
        else 
        {
            arrows++;
            high = points[i][1];
        }
    }

    return arrows;
}

void test(vector<vector<int>> points)
{
    print(points);
    std::cout << "Min number of arrows " << findMinArrowShots(points) << '\n';
}

int main()
{
    test({{10,16},{2,8},{1,6},{7,12}});
    test({{1,2},{3,4},{5,6},{7,8}});
    test({{1,2},{2,3},{3,4},{4,5}});

    test({{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}});

    return 0;
}