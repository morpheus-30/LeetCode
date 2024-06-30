class Solution {
public:
    bool check(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int i, string&s, vector<int>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int j=i; j<s.size(); j++){
            if(check(i, j, s)){
                int cnt=1+f(j+1, s, dp);
                ans=min(ans, cnt);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        vector<int>dp(s.size(), -1);
        return f(0, s, dp)-1;
    }
};