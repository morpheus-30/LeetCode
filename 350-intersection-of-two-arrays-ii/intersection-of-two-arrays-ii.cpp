class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int,int> mp;
         for(auto x:nums1){
            mp[x]++;
         }
         vector<int> ans;
         for(auto x:nums2){
            if(mp.find(x)!=mp.end()){
                mp[x]--;
                if(mp[x]==0){
                    mp.erase(x);
                }
                ans.push_back(x);
            }
         }
         return ans;
    }
};