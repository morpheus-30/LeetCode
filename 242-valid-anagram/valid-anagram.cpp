class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int n = s.size();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        // for(auto x:mp1){
        //     if(mp1[x.first]!=mp2[x.first]){
        //         return false;
        //     }
        // }
        return mp1==mp2;

    }   
};