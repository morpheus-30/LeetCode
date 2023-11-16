class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 1;
        int n = nums.size();
        int high = n-2;
         if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid-1]!=nums[mid]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                    || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                //eliminate the left half:
                low = mid + 1;
            }
            //we are in the right:
            else {
                //eliminate the right half:
                high = mid - 1;
            }
        }
        return -1;
    }
};