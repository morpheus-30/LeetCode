class Solution {
public:

    int solve(string &w1,string &w2,int i1,int i2,vector<vector<int>> &dp){
        if(i1==w1.length()){
            return w2.size()-i2;
        }
        if(i2==w2.length()){
            return w1.size()-i1;
        }
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        int ans = 0;
        if(w1[i1]==w2[i2]){
            return solve(w1,w2,i1+1,i2+1,dp);
        }else{
            int insertAns = 1+solve(w1,w2,i1,i2+1,dp);
            int delAns = 1+solve(w1,w2,i1+1,i2,dp);
            int replAns = 1+solve(w1,w2,i1+1,i2+1,dp);
            ans = min(insertAns,min(delAns,replAns));
        }
        return dp[i1][i2]=ans;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};