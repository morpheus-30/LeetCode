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

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k+1,vector<int>(k/3+1,-1));
        int case1 = solveMem(slices,0,k-2,k/3,dp1);
        vector<vector<int>> dp2(k+1,vector<int>(k/3+1,-1));
        int case2 = solveMem(slices,1,k-1,k/3,dp2);
        return max(case1,case2);
    }
};