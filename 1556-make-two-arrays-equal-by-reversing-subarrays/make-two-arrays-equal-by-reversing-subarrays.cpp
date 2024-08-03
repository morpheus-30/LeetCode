class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x:target){
            mp[x]++;
        }
        for(auto x:arr){
            if(mp.find(x)==mp.end()){
                return false;
            }
            mp[x]--;
        }
        for(auto x:mp){
            if(x.second>0){
                return false;
            }
        }
        return true;
    }
};