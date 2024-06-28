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

        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};