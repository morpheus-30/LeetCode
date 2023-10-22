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

    int solveTab(string &w1,string &w2){
        vector<vector<int>> dp(w1.length()+1,vector<int>(w2.length()+1,0));

        for(int i2 = 0;i2<w2.length();i2++){
            dp[w1.length()][i2]= w2.size()-i2;
        }
        for(int i1 = 0;i1<w1.length();i1++){
            dp[i1][w2.length()]= w1.size()-i1;
        }


        for(int i1 = w1.length()-1;i1>=0;i1--){
            for(int i2 = w2.length()-1;i2>=0;i2--){
                int ans = 0;
                if(w1[i1]==w2[i2]){
                    ans = dp[i1+1][i2+1];
                }else{
                    int insertAns = 1+dp[i1][i2+1];
                    int delAns = 1+dp[i1+1][i2];
                    int replAns = 1+dp[i1+1][i2+1];
                    ans = min(insertAns,min(delAns,replAns));
                }
                dp[i1][i2]=ans;
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solveTab(word1,word2);
    }
};