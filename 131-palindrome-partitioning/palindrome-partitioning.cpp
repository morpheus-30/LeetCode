class Solution {
public:

bool isPallindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }

    void solve(string &s,int index,vector<string> &curr,vector<vector<string>> &ans){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPallindrome(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                solve(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        solve(s,0,curr,ans);
        return ans;
    }
};