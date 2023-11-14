class Solution {
public:

    int solve(vector<int>& nums, int target,int low,int high){
        if(low>high){
            return -1;
        }
        int mid = (low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>target){
            return solve(nums,target,low,mid-1);
        }else{
            return solve(nums,target,mid+1,high);
        }
    }

    int search(vector<int>& nums, int target) {
        return solve(nums,target,0,nums.size()-1);
    }
};