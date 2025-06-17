#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void Helper(int x, int y, vector<vector<int>> &grid, int &cnt, int dirX[], int dirY[])
    {
        cnt++;
        grid[x][y] = -1;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dirX[i], new_y = y + dirY[i];
            if (new_x >= 0 && new_y >= 0 && new_x < grid.size() &&
                new_y < grid[0].size() && grid[new_x][new_y] == 1)
            {
                Helper(new_x, new_y, grid, cnt, dirX, dirY);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        int dirX[] = {1, 0, -1, 0};
        int dirY[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                if (grid[i][j] == 1)
                {
                    Helper(i, j, grid, cnt, dirX, dirY);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    Solution s;
    cout << "Max area is : " << s.maxAreaOfIsland(grid) << endl;
    return 0;
}