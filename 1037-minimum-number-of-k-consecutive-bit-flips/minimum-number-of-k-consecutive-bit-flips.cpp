class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> isFlipped(n, false);
        int flippedQ = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k && isFlipped[i - k] == true) {
                flippedQ--;
            }

            if (flippedQ % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flippedQ++;
                isFlipped[i] = true;
                ans++;
            }
        }
        return ans;
    }
};