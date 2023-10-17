class Solution {
public:

    int solve(vector<int>& nums,int diff,int index,unordered_map<int,int> dp[]){
        if(index<0){
            return 0;
        }
        if(dp[index].count(diff)){
            return dp[index][diff];
        }
        int ans = 0;
        for(int i = index-1;i>=0;i--){
            if(nums[index]-nums[i]==diff){
                ans = max(ans,1+solve(nums,diff,i,dp));
            }
        }
        return dp[index][diff] = ans;
    }

    int solveTab(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,int> dp[n+1];
        int ans = 0;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                int diff = nums[i]-nums[j];
                int count = 1;

                if(dp[j].count(diff)){
                    count = dp[j][diff];
                }
                dp[i][diff] = 1+count;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        // unordered_map<int,int> dp[n];
        // int ans = 0;
        // for(int i = 0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         ans = max(ans,2+solve(nums,nums[j]-nums[i],i,dp));
        //     }
        // }
        return solveTab(nums);
    }
};