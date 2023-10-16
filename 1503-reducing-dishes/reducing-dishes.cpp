class Solution {
public:

    int solve(vector<int> &s,int index,int time){
        int n = s.size();
        if(index==n){
            return 0;
        }
        int incl = s[index]*time + solve(s,index+1,time+1);
        int excl = solve(s,index+1,time);
        return max(incl,excl);
    }

    int solveMem(vector<int> &s,int index,int time,vector<vector<int>> &dp){
        int n = s.size();
        if(index==n){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        int incl = s[index]*time + solveMem(s,index+1,time+1,dp);
        int excl = solveMem(s,index+1,time,dp);
        dp[index][time] = max(incl,excl);
        return dp[index][time];
    }
    int solveTab(vector<int> &s){
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            for(int t = i;t>=0;t--){
                int incl = s[i]*(t+1) + dp[i+1][t+1];
                int excl = dp[i+1][t];
                dp[i][t] = max(incl,excl);
            }
        }
        return dp[0][0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        return solveTab(satisfaction);
    }
};