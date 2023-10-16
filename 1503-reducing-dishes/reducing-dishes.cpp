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

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        return solveMem(satisfaction,0,1,dp);
    }
};