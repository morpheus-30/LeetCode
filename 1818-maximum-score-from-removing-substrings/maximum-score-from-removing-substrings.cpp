class Solution {
public:


    string solver(string s,string comp){
        stack<char> st;
        for(auto fi:s){
            if(!st.empty()&&st.top()==comp[0]&&fi==comp[1]){
                st.pop();
            }else{
                st.push(fi);
            }
        }
        string temp = "";
        while(!st.empty()){
            temp +=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        // cout<<temp<<endl;
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        string greater = x>y?"ab":"ba";
        string smaller = greater=="ab"?"ba":"ab";
        // cout<<greater<<smaller;
        int ans =0;
        string temp1 = solver(s,greater);
        ans+=max(x,y)*((s.size()-temp1.size())/2);
        string temp2 = solver(temp1,smaller);
        ans+=min(x,y)*((temp1.size()-temp2.size())/2);

        return ans;
    }
};