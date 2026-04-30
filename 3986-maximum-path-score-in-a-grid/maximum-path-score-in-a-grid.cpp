class Solution {
public:
    int m, n;

    bool isValid(int i, int j) { return i >= 0 && j >= 0 && i < m && j < n; }

    int getCost(int i) {
        if (i == 0 || i == 1) {
            return i;
        }
        if (i == 2) {
            return 1;
        }
        return -1;
    }

    int solve(vector<vector<int>>& grid, int i, int j, int rem,
              vector<vector<vector<int>>>& dp) {

        int c = (grid[i][j] == 2 ? 1 : grid[i][j]);
        if (rem < c)
            return INT_MIN;

        rem -= c;

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int right = INT_MIN, down = INT_MIN;

        if (j + 1 < n)
            right = solve(grid, i, j + 1, rem, dp);

        if (i + 1 < m)
            down = solve(grid, i + 1, j, rem, dp);

        int best = max(right, down);

        if (best == INT_MIN)
            return dp[i][j][rem] = INT_MIN;

        return dp[i][j][rem] = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int ans = solve(grid, 0, 0, k, dp);
        if (ans < 0) {
            return -1;
        } else {
            return ans;
        }
    }
};