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

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solveMem(obstacles,2,0,n,dp);
    }
};