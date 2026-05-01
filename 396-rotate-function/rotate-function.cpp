class Solution {
public:
int n;

    // int solve(vector<int> &nums, int i, int r,vector<vector<int>> &dp){
    //     if(i==n){
    //         return 0;
    //     }

    //     if(dp[i][r]!=-1){
    //         return dp[i][r];
    //     }

    //     return dp[i][r] = nums[i] * ( ( i + r ) % n ) + solve(nums,i+1,r,dp);
    // }

    // int maxRotateFunction(vector<int>& nums) {  
    //     n = nums.size();

    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     int ans = INT_MIN;
    //     for(int r = 0;r<n;r++){
    //         ans = max(ans,solve(nums,0,r,dp) );
    //         cout<<ans<<endl;
    //     }
    //     return ans;
    // }
    int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    
    long sum = 0, f = 0;
    
    for(int i = 0; i < n; i++){
        sum += nums[i];
        f += (long)i * nums[i];
    }
    
    long ans = f;
    
    for(int k = 1; k < n; k++){
        f = f + sum - (long)n * nums[n - k];
        ans = max(ans, f);
    }
    
    return ans;
}
};