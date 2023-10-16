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

    int solveTab(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int currIndex = n-1;currIndex>=0;currIndex--){
            for(int prevIndex = currIndex-1;prevIndex>=-1;prevIndex--){
                int take = 0;
                if(prevIndex==-1||nums[currIndex]>nums[prevIndex]){
                    take = 1+dp[currIndex+1][currIndex+1];
                }
                int notTake = dp[currIndex+1][prevIndex+1];
                dp[currIndex][prevIndex+1] = max(take,notTake);
            }
        }
        return dp[0][0]; 
    }

    int solveOptimal(vector<int> &nums){
        int n = nums.size();
        if(n==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solveOptimal(nums);
    }
};