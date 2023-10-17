class Solution {
public:

    int solve(int n,int k,int target){
        if(target<0){
            return 0;
        }
        if(n==0&&target!=0){
            return 0;
        }
        if(target==0&&n!=0){
            return 0;
        }
        if(target==0&&n==0){
            return 1;
        }
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans+=solve(n-1,k,target-i);
        }
        return ans;
    }
    int solveMem(int n,int k,int target,vector<vector<int>> &dp){
        int mod = 1e9+7;
        if(target<0){
            return 0;
        }
        if(n==0&&target==0){
            return 1;
        }
        if(n==0&&target!=0){
            return 0;
        }
        if(target==0&&n!=0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = (ans+solveMem(n-1,k,target-i,dp))%mod;
        }
        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solveMem(n,k,target,dp);
    }
};