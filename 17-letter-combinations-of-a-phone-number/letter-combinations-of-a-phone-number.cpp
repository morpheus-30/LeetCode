class Solution {
public:

    void solve(unordered_map<char,string> &mp,string digits,int index,int n,vector<string> &ans,string currS){
        if(index==n){
            ans.push_back(currS);
            return;
        }
        for(auto x:mp[digits[index]]){
            currS+=x;
            solve(mp,digits,index+1,n,ans,currS);
            currS.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        solve(mp,digits,0,digits.size(),ans,"");
        if(ans[0]==""){
            return {};
        }
        return ans;

    }
};