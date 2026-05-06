class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = INT_MAX;
        int down = INT_MAX;

        if (j + 1 < n) {
            right = solve(grid, i, j + 1);
        }

        if (i + 1 < m) {
            down = solve(grid, i + 1, j);
        }

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));

        return solve(grid, 0, 0);
    }
};