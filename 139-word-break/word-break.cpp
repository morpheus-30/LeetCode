class Solution {
public:

    bool solve(int index,string s,vector<string> &wordDict,vector<int> &dp){
        if(index==s.size()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        string temp = "";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                if(solve(i+1,s,wordDict,dp)){
                    return dp[index]=true;
                }
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(3011, -1);
        return solve(0,s,wordDict,dp);
    }
};