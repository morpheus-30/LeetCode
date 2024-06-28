class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    // dp[i] = max(dp[i],1+dp[j]);
                    if( dp[j]+1>dp[i]){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }else if(dp[j]+1==dp[i]){
                        count[i] = count[j]+count[i];
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            // cout<<dp[i]<<" "<<maxi<<" "<<count[i]<<endl;
            if(dp[i]==maxi){
                ans+=count[i];
            }
        }
        return ans;
    }
};