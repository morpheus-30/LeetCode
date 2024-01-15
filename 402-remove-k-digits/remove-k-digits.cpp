#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        int digitsRemoved = 0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&digitsRemoved<k&&num[i]<st.top()){
                st.pop();
                digitsRemoved++;
            }
            st.push(num[i]);
        }
        while(!st.empty()&&digitsRemoved<k){
            st.pop();
            digitsRemoved++;
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int index = ans.size()-1;
        while(index>=0&&ans[index]=='0'){
            ans.pop_back();
            index--;
        }
        reverse(ans.begin(),ans.end());
        if(ans==""){
            return "0";
        }
        return ans;

    }
};