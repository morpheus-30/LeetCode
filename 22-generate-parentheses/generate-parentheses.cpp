#include<bits/stdc++.h>

class Solution {
public:

    
    void solve(vector<string> &ans,int count,string currS,int absCount,int n){
        if(count==0&&absCount==n){
            ans.push_back(currS);
            return;
        }
        if(absCount>n||count<0||count>n){
            return;
        }
        cout<<currS<<" "<<count<<" "<<absCount<<endl;
        currS+='(';
        solve(ans,count+1,currS,absCount+1,n);
        currS.pop_back();
        currS+=')';
        solve(ans,count-1,currS,absCount,n);
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,0,"",0,n);
        return ans;
        
    }
};