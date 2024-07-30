class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> st;
        int count = 0;
        for(auto x:s){
            if(st.empty()){
                st.push(x);
                continue;
            }
            if(st.top()=='b'&&x=='a'){
                st.pop();
                count++;
            }else{
                st.push(x);
            }
        }
        return count;
    }
};