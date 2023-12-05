class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        string currComp = "";
        for(auto x:s){
            if(x=='('){
                count++;
            }else{
                count--;
            }
            currComp+=x;
            if(count==0){
                string comp = currComp.substr(1,currComp.size()-2);
                ans+=comp;
                currComp = "";
            }
        }
        return ans;

    }
};