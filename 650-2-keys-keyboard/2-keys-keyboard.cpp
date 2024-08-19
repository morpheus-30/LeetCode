class Solution {
public:

    int solve(string curr,int n,string currCopy,vector<vector<int>> &dp){
        // cout<<ccurr<<" "<<currCopy<<endl;
        if(curr.size()>n){
            return 1e9;
        }
        if(curr.size()==n){
            return 1;
        }
        if(dp[curr.size()][currCopy.size()]!=-1){
            return dp[curr.size()][currCopy.size()];
        }
        //copy all
        int an1 = INT_MAX;
        if(curr!=currCopy){
            an1 = 1+solve(curr,n,curr,dp);
        }
        int an2 = 1+solve(curr+currCopy,n,currCopy,dp);
        //paste curr copy
        return dp[curr.size()][currCopy.size()] = min(an1,an2);

    }

    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        vector<vector<int>> mp(n+1,vector<int>(n+1,-1));
        return solve("A",n,"A",mp);
    }
};