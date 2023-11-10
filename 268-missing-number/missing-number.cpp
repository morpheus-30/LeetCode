class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int initial_sum = 0;
        int sumNums = accumulate(nums.begin(), nums.end(), initial_sum);
        int ideal = n*(n+1)/2;
        return ideal-sumNums;
    }
};