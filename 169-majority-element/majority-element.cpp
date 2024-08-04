class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        if(nums.size()<=2){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        return nums[(nums.size()/2)];
    }
};