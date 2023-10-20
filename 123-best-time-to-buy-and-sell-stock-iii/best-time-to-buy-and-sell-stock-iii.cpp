class Solution {
public:

    int solve(vector<int>& prices,int index,int buy,int limit,vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(index==n||limit==0){
            return 0;
        }
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index]+solve(prices,index+1,0,limit,dp);
            int skipKaro = 0+solve(prices,index+1,1,limit,dp);
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = prices[index]+solve(prices,index+1,1,limit-1,dp);
            int skipKaro = 0+solve(prices,index+1,0,limit,dp);
            profit = max(sellKaro,skipKaro);
        }
        return dp[index][buy][limit] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,2,dp);
    }
};