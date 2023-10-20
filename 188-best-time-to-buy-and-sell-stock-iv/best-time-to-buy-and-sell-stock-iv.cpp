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

    int solveTab(vector<int> &prices,int k){
        int n = prices.size();
        if(n==0){
            return 0;
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit = 0;limit<=k;limit++){
                    if(limit==0){
                        continue;
                    }
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index]+dp[index+1][0][limit];
                        int skipKaro = 0+dp[index+1][1][limit];
                        profit = max(buyKaro,skipKaro);
                    }else{
                        int sellKaro = prices[index]+dp[index+1][1][limit-1];
                        int skipKaro = 0+dp[index+1][0][limit];
                        profit = max(sellKaro,skipKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];

    }

    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(3,-1)));
        return solveTab(prices,k);
    }
};