class Solution {
public:

    int solve(vector<int>& slices,int sind,int eind,int n){
        if(n==0||sind>eind){
            return 0;
        }
        int take = slices[sind]+solve(slices,sind+2,eind,n-1);
        int notTake = solve(slices,sind+1,eind,n);
        return max(take,notTake);
        
    }
    int solveMem(vector<int>& slices,int sind,int eind,int n,vector<vector<int>> &dp){
        if(n==0||sind>eind){
            return 0;
        }
        if(dp[sind][n]!=-1){
            return dp[sind][n];
        }
        int take = slices[sind]+solveMem(slices,sind+2,eind,n-1,dp);
        int notTake = solveMem(slices,sind+1,eind,n,dp);
        dp[sind][n] = max(take,notTake);
        return dp[sind][n];
        
    }

    int solveTab(vector<int> s){
        int k = s.size();
        if(k==0){
            return 0;   
        }
        vector<vector<int>> dp1(k+2,vector<int>(k/3+1,0));
        vector<vector<int>> dp2(k+2,vector<int>(k/3+1,0));
        for(int i = k-2;i>=0;i--){
            for(int j = 1;j<=k/3;j++){
                int take = s[i]+dp1[i+2][j-1];
                int notTake = dp1[i+1][j];
                dp1[i][j] = max(take,notTake);
            }
        }
        for(int i = k-1;i>=1;i--){
            for(int j = 1;j<=k/3;j++){
                int take = s[i]+dp2[i+2][j-1];
                int notTake = dp2[i+1][j];
                dp2[i][j] = max(take,notTake);
            }
        }
    return max(dp1[0][k/3],dp2[1][k/3]);
        

    }

    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // vector<vector<int>> dp1(k+1,vector<int>(k/3+1,-1));
        // int case1 = solveMem(slices,0,k-2,k/3,dp1);
        // vector<vector<int>> dp2(k+1,vector<int>(k/3+1,-1));
        // int case2 = solveMem(slices,1,k-1,k/3,dp2);
        // return max(case1,case2);
        return solveTab(slices);
    }
};