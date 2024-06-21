class Solution {
public:
    int func(vector<vector<int>>& dp, vector<int>& v, int num, int ind) {
        int n = v.size();
        if (ind == n) return num == 0;
        if (num + 1000 < 0 || num + 1000 >= 2001) return 0; 
        if (dp[ind][num + 1000] != -1) return dp[ind][num + 1000];

        int ntake = func(dp, v, num + v[ind], ind + 1);
        int take = func(dp, v, num - v[ind], ind + 1);
        return dp[ind][num + 1000] = (take + ntake);
    }

    int findTargetSumWays(vector<int>& v, int num) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return func(dp, v, num, 0); 
    }
};