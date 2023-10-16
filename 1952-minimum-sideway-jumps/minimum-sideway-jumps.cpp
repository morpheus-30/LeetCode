class Solution {
public:

    int solve(vector<int> &o,int currLane,int currPosn,int n){
        if(currPosn==n-1){
            return 0;
        }
        if(o[currPosn+1]!=currLane){
            return solve(o,currLane,currPosn+1,n);
        }else{
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=currLane&&o[currPosn]!=i){
                    ans = min(ans,1+solve(o,i,currPosn,n));
                }
            }
            return ans;
        }
    }

    int solveMem(vector<int> &o,int currLane,int currPosn,int n,vector<vector<int>> &dp){
        if(currPosn==n-1){
            return 0;
        }
        if(dp[currLane][currPosn]!=-1){
            return dp[currLane][currPosn];
        }
        if(o[currPosn+1]!=currLane){
            return solveMem(o,currLane,currPosn+1,n,dp);
        }else{
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=currLane&&o[currPosn]!=i){
                    ans = min(ans,1+solveMem(o,i,currPosn,n,dp));
                }
            }
            dp[currLane][currPosn] = ans;
            return dp[currLane][currPosn];
        }
    }
    int solveTab(vector<int> &o){
        int n = o.size()-1;
        vector<vector<int>> dp(4,vector<int>(n+1,1e9));
        for(int i=0;i<4;i++){
            dp[i][n] = 0;
        }
        for(int currPosn = n-1;currPosn>=0;currPosn--){
            for(int currLane=1;currLane<=3;currLane++){
                 if(o[currPosn+1]!=currLane){
                    dp[currLane][currPosn] = dp[currLane][currPosn+1];
                }else{
                    int ans = INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(i!=currLane&&o[currPosn]!=i){
                            ans = min(ans,1+dp[i][currPosn+1]);
                        }
                    }
                    dp[currLane][currPosn] = ans;
                }
            }
        }
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
        
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solveTab(obstacles);
    }
};