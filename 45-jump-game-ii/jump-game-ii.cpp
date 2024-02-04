class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[0]=0;
        for(int po=1;po<nums.size();po++){
            dp[po]=INT_MAX;
        }
        for(int po=0;po<nums.size();po++){
            if(dp[po]<INT_MAX){
                for(int p=1;p<=nums[po];p++){
                 if((po+p)<nums.size())
                 dp[po+p]=min(dp[po]+1,dp[po+p]);
                }
            }
            if(po+1==nums.size())
            return dp[po];
        }
 return dp[nums.size()];   }
};