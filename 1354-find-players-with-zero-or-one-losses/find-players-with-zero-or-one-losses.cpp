class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
        for(auto x:matches){
            if(mp.find(x[0])==mp.end()){
                mp[x[0]] = 0;
            }
            mp[x[1]]++;
        }
        vector<int> noLost;
        vector<int> oneLost;
        for(auto x:mp){
            if(x.second==0){
                noLost.push_back(x.first);
            }else if(x.second==1){
                oneLost.push_back(x.first);
            }
        }
        sort(noLost.begin(),noLost.end());
        sort(oneLost.begin(),oneLost.end());
        vector<vector<int>> ans;
        ans.push_back(noLost);
        ans.push_back(oneLost);
        return ans;
    }
};