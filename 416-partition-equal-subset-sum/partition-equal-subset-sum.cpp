class Solution {
public:

    bool solve(vector<int> &nums,int index,int target){
        int n = nums.size();
        if(target<0){
            return 0;
        }
        if(index>=n){
            return 0;
        }
        if(target==0){
            return 1;
        }
        int incl = solve(nums,index+1,target-nums[index]);
        int excl = solve(nums,index+1,target);
        return incl or excl;

    }
    bool solveMem(vector<int> &nums,int index,int target,vector<vector<int>> &dp){
        int n = nums.size();
        if(target<0){
            return 0;
        }
        if(index>=n){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int incl = solveMem(nums,index+1,target-nums[index],dp);
        int excl = solveMem(nums,index+1,target,dp);
        return dp[index][target] = (incl or excl);

    }
    bool solveTab(vector<int> &nums,int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int i = n-1;i>=0;i--){
            for(int t = 1;t<=target;t++){
                int incl = 0;
                if(t-nums[i]>=0){
                    incl = dp[i+1][t-nums[i]];
                }
                
                int excl = dp[i+1][t];
                dp[i][t] = (incl or excl);
            }
        }
        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return solveTab(nums,sum/2);
    }
};