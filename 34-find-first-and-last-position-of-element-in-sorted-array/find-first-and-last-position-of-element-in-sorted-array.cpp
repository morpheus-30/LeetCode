class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int n = nums.size();
        int high = n-1;
        int low = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                int midC = mid;
                while(mid>=0&&nums[mid]==target){
                    ans[0] = mid;
                    mid--;
                }
                mid = midC;
                while(mid<n&&nums[mid]==target){
                    ans[1] = mid;
                    mid++;
                }
                return ans;
            }
            if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};