class Solution {
public:

    int solve(vector<int> nums,int currIndex,int prevIndex){
        int n = nums.size();
        if(currIndex==n){
            return 0;            
        }
        int take = 0;
        if(prevIndex==-1||nums[currIndex]>nums[prevIndex]){
            take = 1+solve(nums,currIndex+1,currIndex);
        }
        int notTake = solve(nums,currIndex+1,prevIndex);
        return max(take,notTake);
    }
    int solveMem(vector<int> &nums,int currIndex,int prevIndex,vector<vector<int>> &dp){
        int n = nums.size();
        if(currIndex==n){
            return 0;            
        }
        if(dp[currIndex][prevIndex+1]!=-1){
            return dp[currIndex][prevIndex+1];
        }
        int take = 0;
        if(prevIndex==-1||nums[currIndex]>nums[prevIndex]){
            take = 1+solveMem(nums,currIndex+1,currIndex,dp);
        }
        int notTake = solveMem(nums,currIndex+1,prevIndex,dp);
        dp[currIndex][prevIndex+1] = max(take,notTake);
        return dp[currIndex][prevIndex+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solveMem(nums,0,-1,dp);
    }
};