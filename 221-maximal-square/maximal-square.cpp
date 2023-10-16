class Solution {
public:

    int solve(vector<vector<char>>& matrix,int i,int j,int &maxi){
        int m = matrix.size();
        int n = matrix[0].size();
        if(i>=m||j>=n){
            return 0;
        }
        int right = solve(matrix,i,j+1,maxi);
        int down = solve(matrix,i+1,j,maxi);
        int diag = solve(matrix,i+1,j+1,maxi);

        if(matrix[i][j]=='1'){
            int ans = 1+min(right,min(down,diag));
            maxi = max(maxi,ans);
            return ans;
        }else{
            return 0;
        }
    }
    int solveMem(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>> &dp){
        int m = matrix.size();
        int n = matrix[0].size();
        if(i>=m||j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = solveMem(matrix,i,j+1,maxi,dp);
        int down = solveMem(matrix,i+1,j,maxi,dp);
        int diag = solveMem(matrix,i+1,j+1,maxi,dp);

        if(matrix[i][j]=='1'){
            dp[i][j] = 1+min(right,min(down,diag));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }else{
            return 0;
        }
    }
    // int solveTab(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>> &dp){
        
    // }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        solveMem(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};

// #include <algorithm>
// #include <vector>
// class Solution {
// public:
// int solve(vector<vector<char>>& matrix, int i , int j ,int& maxi,vector<vector<int>>&dp)
// {
//     // CHECK IF INDEX ARE OUT OF BOUND OR NOT 
//     if(i>=matrix.size() || j>=matrix[0].size())
//     {
//         return 0 ;
//     }

//     if(dp[i][j]!=-1)
//     {
//         return dp[i][j];
//     }
//     int right=solve(matrix,i,j+1,maxi,dp);
//     int diagonal=solve(matrix,i+1,j+1,maxi,dp);
//     int bottom=solve(matrix,i+1,j,maxi,dp);
//     if(matrix[i][j]=='1')
//     {
//         dp[i][j] = 1+min(right, min(diagonal , bottom));
//         maxi=max(dp[i][j],maxi);
//         return dp[i][j];
//     }
//     else
//         return 0 ;

// }
//     int maximalSquare(vector<vector<char>>& matrix)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));

//         int maxi = 0;
//         int s=solve(matrix, 0,0 , maxi,dp);
//           return maxi * maxi; 
//     }
// };