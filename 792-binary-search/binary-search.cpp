class Solution {
public:
    int search(vector<int>& nums, int target) {
        int found = -1;
        int n = nums.size();
        int high = n-1;
        int low = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return found;


    }
};