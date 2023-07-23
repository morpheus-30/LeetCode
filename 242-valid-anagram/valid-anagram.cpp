class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sm;
        if(t.size()!=s.size()){
            return false;
        }
        for(auto x:s){
            if(!sm[x]){
                sm[x] = 0;
            }
            sm[x]++;
        }
        for(auto x:t){
            if(!sm[x]){
                return false;
            }
            sm[x]--;
        }
        return true;

    }
};