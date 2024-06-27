class Solution {
public:


    int solve(vector<int>&nums,int index,int lastIndex,vector<vector<int>> &dp){
        if(index<0){
            return 0;
        }
        if(dp[index][lastIndex+1]!=-1){
            return dp[index][lastIndex+1];
        }
        int take = 0;
        if(lastIndex==-1||nums[lastIndex]<nums[index]){
            take = 1+solve(nums,index-1,index,dp);
        }
        int nottake = solve(nums,index-1,lastIndex,dp);
        return dp[index][lastIndex+1] = max(take,nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        int n = nums.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        return solve(nums,n,-1,dp);
    }
};