class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int n = s.size();
        // unordered_map<char,int> mp1;
        // unordered_map<char,int> mp2;
        vector<int> v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-97]++;
            v[t[i]-97]--;
        }
        // for(auto x:mp1){
        //     if(mp1[x.first]!=mp2[x.first]){
        //         return false;
        //     }
        // }
        for(auto x:v){
            if(x!=0){
                return false;
            }
        }
        return true;

    }   
};