class Solution {
public:

    int solve(vector<int> &prices,int index,int buy,vector<vector<int>> &dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index]+solve(prices,index+1,0,dp);
            int skipKaro = solve(prices,index+1,1,dp);
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = prices[index]+solve(prices,index+1,1,dp);
            int skipKaro = solve(prices,index+1,0,dp);
            profit = max(sellKaro,skipKaro);
        }
        return dp[index][buy] = profit;

    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,dp);

    }
};