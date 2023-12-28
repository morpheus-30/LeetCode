class Solution {
public:
    bool isPallindrome(string s){
        int n = s.size();
        if(n==1){
            return true;
        }
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    bool check(vector<string> s,string checkS){
        if(s.size()==0){
            return false;
        }
        string temp = "";  
        for(auto x:s){
            temp+=x;
        }
        return temp==checkS;
    }

    void solve(string &s,int index,int initial,vector<vector<string>> &ans,vector<string> curr){
        // cout<<initial<<" "<<index<<endl; 
        if(index==s.size()){
            if(check(curr,s)){
                ans.push_back(curr);
            }
            return;
        }
        // cout<<s.substr(initial,index-initial+1)<<endl;
        bool flag = false;
        if(isPallindrome(s.substr(initial,index-initial+1))){
            curr.push_back(s.substr(initial,index-initial+1));
            flag = true;
            solve(s,index+1,index+1,ans,curr);
        }
        if(flag){
            curr.pop_back();
        }
        solve(s,index+1,initial,ans,curr);
        

        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        
        vector<string> curr;
        solve(s,0,0,ans,curr);
        return ans;
    }
};