class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xori = 0;
        for(auto x:nums){
            xori = xori^x;
        }
        return xori;
    }
};