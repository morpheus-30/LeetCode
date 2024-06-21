class Solution {
public:

    int solve(int index,vector<int>& nums,int target){
        // if(dp[index][target]!=-1){
        //     return dp[index][target];
        // }
        // cout<<target<<" "index<<endl;
        if(index==0){
            if(target==0&&nums[index]==0){
                return 2;
            }
            
            return nums[index]==target||nums[index]==(-1*target);
        }
        
        int minus = solve(index-1,nums,target+nums[index]);
        int plus = solve(index-1,nums,target-nums[index]);
        return minus+plus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1,nums,target*-1);
    }
};


