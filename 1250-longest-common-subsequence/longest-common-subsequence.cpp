class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(string text1,string text2,int i,int j){
        if(i==m || j == n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int mat = 0;
        if(text1[i] == text2[j]){
            //matched increment both
            mat = 1 + solve(text1,text2,i+1,j+1);
        }

        //not mat
        int notmat = max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));

        return dp[i][j] = max(mat,notmat);
    }

    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        dp = vector<vector<int>>(m+1,vector<int>(n+1,0));

        // return solve(text1,text2,0,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                }else{
                    dp[i+1][j+1] = max({dp[i][j],dp[i][j+1],dp[i+1][j]});
                }
            }
        }
        return dp[m][n];
    }
};

//tab
