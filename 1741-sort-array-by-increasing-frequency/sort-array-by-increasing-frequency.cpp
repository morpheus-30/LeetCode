class Solution {
public:
    

    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }else{
            return a.first<b.first;
        }
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto x:mp){
            vec.push_back({x.second,x.first});
        }

        sort(vec.begin(),vec.end(),cmp);
        
        vector<int> ans;
        for(auto x:vec){
            while(x.first){
                ans.push_back(x.second);
                x.first--;
            }
        }
        return ans;

    }
};