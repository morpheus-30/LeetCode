class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxi = INT_MIN;
        for(auto x:nums){
            maxi = max(maxi,x);
        }
        int cnt = 0;
        while(right<n){
            if(nums[right]==maxi){
                cnt++;
            }
            while(cnt>=k){
                if(nums[left]==maxi){
                    cnt--;
                }
                left++;
                ans+=n-right;
            }
            right++;
        }
        return ans;
    }
};
