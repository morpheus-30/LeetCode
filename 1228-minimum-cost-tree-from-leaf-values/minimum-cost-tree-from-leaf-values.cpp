class Solution {
public:

    int solve(vector<int> &arr,map<pair<int,int>,int>& maxi,int left,int right,vector<vector<int>> &dp){
        if(left==right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int k = left;k<right;k++){
            ans = min(ans,maxi[{left,k}]*maxi[{k+1,right}]+solve(arr,maxi,left,k,dp)+solve(arr,maxi,k+1,right,dp));
        }
        return dp[left][right] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1;j<n;j++){
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solve(arr,maxi,0,n-1,dp);
    }
};