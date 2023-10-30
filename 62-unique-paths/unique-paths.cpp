class Solution {
public:
    
    int solve(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i>=n||j>=m){
            return 0;
        }
        if(i==n-1&&j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(m,n,i+1,j,dp);
        int down=solve(m,n,i,j+1,dp);
        dp[i][j] = right+down;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        if(m==1&&n==1){
            return 1;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        dp[n-1][m-1] = 1;
        // int ans = 0
        return solve(m,n,0,0,dp);
    }
};