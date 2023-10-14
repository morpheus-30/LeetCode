class Solution {
public:

    int solve(vector<int>& nums,int target){
        if(target==0){
            return 1;
        }
        if(target<=0){
            return 0;
        }
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans +=solve(nums,target-nums[i]);
        }
        return ans;
    }
    int solveMem(vector<int>& nums,int target,vector<int> &dp){
        if(target==0){
            dp[target] = 1;
            return 1;
        }
        if(target<=0){
            dp[target] = 0;
            return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(target-nums[i]>=0){
                ans +=solveMem(nums,target-nums[i],dp);
            }
            
        }
        dp[target] = ans;
        return ans;
    }
    int solveTab(vector<int> &nums,int target){
        vector<unsigned> dp(target+1,0);
        dp[0] = 1;
        int n = nums.size();
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if((i-nums[j])>=0){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1,-1);
        return solveTab(nums,target);
    }
};