class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,int index,vector<int> &dp){
        int n = days.size();
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int o1 = costs[0]+solve(days,costs,index+1,dp);
        
        int i;
        for(i=index;i<n&&(days[i]<days[index]+7);i++);
        int o2 = costs[1]+solve(days,costs,i,dp);
        for(i=index;i<n&&(days[i]<days[index]+30);i++);
        int o3 = costs[2]+solve(days,costs,i,dp);
        dp[index] = min(o1,min(o2,o3));
        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return solve(days,costs,0,dp);
    }
};