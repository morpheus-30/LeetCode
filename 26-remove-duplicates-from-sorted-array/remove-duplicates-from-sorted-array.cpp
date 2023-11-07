class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums){
            if(mp.find(x)==mp.end()){
                mp[x] = 1;
            }else{
                mp[x]++;
            }
        }
        int i = 0;
        for(auto x:mp){
            nums[i] = x.first;
            i++;
        }
        return mp.size();
    }
};