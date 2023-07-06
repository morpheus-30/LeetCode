class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(i==nums.size()-1){
                return nums[i];
            }
            if(nums[i+1]==nums[i]){
                i+=2;
            }else{
                return nums[i];
            }
        }
        return -1;
    }
};