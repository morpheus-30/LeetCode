class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                // if(curr!=""){
                    st.push(curr);
                    curr = "";
                    // curr+=s[i];
                // }
            }else if(s[i]==')'){
                reverse(curr.begin(),curr.end());
                // st.push_back();
                if(!st.empty()){
                curr = st.top()+curr;
                st.pop();
                }
            }else{
                curr+=s[i];
            }
        }
        return curr;
    }
};