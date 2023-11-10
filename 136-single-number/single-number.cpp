class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        unordered_map<int,int> mp;
        for(auto x:nums){
            if(mp.find(x)==mp.end()){
                mp[x] = 1;
            }else{
                mp[x]++;
            }
        }
        for(auto x:mp){
            if(x.second==1){
                return x.first;
            }
        }
        return -1;
    }
};