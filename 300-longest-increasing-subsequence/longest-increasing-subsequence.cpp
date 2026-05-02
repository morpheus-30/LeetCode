class Solution {
public:
    int n;
    int solve(int i,vector<int> &nums,int prevIndex,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }

        if(dp[i][prevIndex+1]!=-1){
            return dp[i][prevIndex+1];
        }
        
        //pick
        int pick = 0;
        if(prevIndex == -1 || nums[prevIndex] < nums[i]){
            pick = 1 + solve(i+1,nums,i,dp);
        }

        //not pick
        int notPick = solve(i+1,nums,prevIndex,dp);

        return dp[i][prevIndex+1] = max(pick,notPick);
    
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};