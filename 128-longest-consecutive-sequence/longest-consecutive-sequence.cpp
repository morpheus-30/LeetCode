class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans = 1;
        int n = nums.size();
        int curr = 1;
        int pre = nums[0];
        for(int i=1;i<n;i++){
            if(pre + 1 == nums[i]){
                curr++;
            }else if(pre!=nums[i]){
                curr = 1;
            }
                pre = nums[i];
                ans = max(ans,curr);
        }
        return ans;

    }
};