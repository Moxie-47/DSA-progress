#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void Helper(int x, int y, vector<vector<int>> &grid, int &cnt, vector<pair<int, int>> dir)
    {
        stack<pair<int, int>> st;
        st.push({x, y});
        while (!st.empty())
        {
            auto [cx, cy] = st.top();
            st.pop();
            cnt++;

            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dir[i].first, ny = cy + dir[i].second;
                if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = -1;
                    st.push({nx, ny});
                }
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                if (grid[i][j] == 1)
                {
                    grid[i][j] = -1;
                    Helper(i, j, grid, cnt, dir);
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