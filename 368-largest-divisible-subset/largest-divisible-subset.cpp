class Solution {
public:

    vector<int> func1(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        int maxiIndex = -1;
        int maxi = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                maxiIndex = i;
            }
        }
        
        vector<int> ans(maxi,-1);
        ans[0] = nums[maxiIndex];
        int index = 1;
        while(maxiIndex!=hash[maxiIndex]){
            maxiIndex = hash[maxiIndex];
            ans[index++]=(nums[maxiIndex]);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }  

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans1 = func1(nums);
   
        return ans1;
    }
};