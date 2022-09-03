/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-01-17 23:12:43
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-01-17 23:51:30
 * @FilePath: /leetcode/934.最短的桥.cpp
 */
/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution
{
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        bool flipped = false;

        for (int i = 0; i < m; i++)
        {
            if (flipped)
            {
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }

        int x, y;
        int level = 0;

        while (!points.empty())
        {
            ++level;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                points.pop();
                for (int k = 0; k < 4; k++)
                {
                    x = r + direction[k];
                    y = c + direction[k + 1];

                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        if (grid[x][y] == 1)
                        {
                            return level;
                        }

                        if (grid[x][y] == 2)
                        {
                            continue;
                        }

                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, int m, int n, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2)
        {
            return;
        }

        if (grid[i][j] == 0)
        {
            points.push({i, j});
            return;
        }

        grid[i][j] = 2;

        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i, j + 1);
        dfs(points, grid, m, n, i, j - 1);
    }
};
// @lc code=end
