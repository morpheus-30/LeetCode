class Solution {
public:

    int func(vector<vector<vector<int>>>& dp, vector<int>& v, int ind, bool flg, bool cool) {
        int n = v.size();
        if (ind == n) return 0;
        if (dp[ind][flg][cool] != -1) return dp[ind][flg][cool];

        int ans = 0;

        if (flg) {
            int take = 0;
            if(cool==0) take = -v[ind] + func(dp, v, ind + 1, 0, 0);
            int ntake = func(dp, v, ind + 1, 1, 0);
            ans = max(take, ntake);
        } 
        else {
            int take = v[ind] + func(dp, v, ind + 1, 1,1);
            int ntake = func(dp, v, ind + 1, 0, 0);
            ans = max(take, ntake);
        }

        return dp[ind][flg][cool] = ans;
    }

    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));
        return func(dp, v, 0, 1, 0);
    }
};