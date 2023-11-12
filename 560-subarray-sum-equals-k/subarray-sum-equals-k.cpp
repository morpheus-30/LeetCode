class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       int n = nums.size();
       int preSum = 0;
       int count = 0;
       mp[0] = 1;
       for(int i=0;i<n;i++){
            preSum+=nums[i];
            int remove = preSum-k;
            count+=mp[remove];
            mp[preSum]++;

       }
       return count;
    }
};