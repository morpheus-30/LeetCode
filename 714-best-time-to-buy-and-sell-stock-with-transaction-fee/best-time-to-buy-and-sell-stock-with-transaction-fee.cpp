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
    
    int solveTab(vector<int> &prices,int fee){
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n = prices.size();
        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index]+dp[index+1][0];
                    int skipKaro = dp[index+1][1];
                    profit = max(buyKaro,skipKaro);
                }else{
                    int sellKaro = prices[index]+dp[index+1][1]-fee;
                    int skipKaro = dp[index+1][0];
                    profit = max(sellKaro,skipKaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }


    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solveTab(prices,fee);

    }
};