class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '&&temp!=""){
                st.push(temp);
                temp = "";
            }else if(i==s.size()-1&&(temp!=""||s[i]!=' ')){
                temp=temp+s[i];
                st.push(temp);
            }else if(s[i]!=' '){
                temp=temp+s[i];
            }
        }
        string final="" ;
        while(!st.empty()){
            if(st.top()==""){
                st.pop();
                continue;
            }else{
                final = final+st.top();
                st.pop();
                if(st.size()==0){
                    continue;
                }
                final = final+" ";
            }
        }
        return final;
    }
};