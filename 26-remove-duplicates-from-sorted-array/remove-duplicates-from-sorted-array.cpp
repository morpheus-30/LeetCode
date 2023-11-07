class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        int i=0;
        for(auto x:s){
            nums[i] = x;
            i++;
        }
        return s.size();
    }
};