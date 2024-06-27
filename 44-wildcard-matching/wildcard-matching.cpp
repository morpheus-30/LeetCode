class Solution {
public:
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp) {
        if (j < 0 && i < 0) {
            return true;
        }

        if (i < 0) {
            for (int index = j; index >= 0; index--) {
                if (p[index] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (j < 0) {
            return false;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }
        if (p[j] == '*') {
            return dp[i][j] =
                       solve(s, p, i - 1, j, dp) || solve(s, p, i, j - 1, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // return solve(s,p,m-1,n-1,dp);
        dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            dp[0][j + 1] = true;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};