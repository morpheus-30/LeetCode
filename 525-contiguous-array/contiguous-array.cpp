#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> sumMap;
        int maxLength = 0;
        int sum = 0;
        
        sumMap[0] = -1; // Initialize with 0 sum at index -1
        
        for (int i = 0; i < nums.size(); ++i) {
            // Increment sum for 1, decrement for 0
            sum += (nums[i] == 1) ? 1 : -1;
            
            // If the same sum is encountered again, it means that
            // the subarray between the previous occurrence and this
            // one has equal number of 0s and 1s
            if (sumMap.find(sum) != sumMap.end()) {
                maxLength = std::max(maxLength, i - sumMap[sum]);
            } else {
                sumMap[sum] = i; // Store the index of first occurrence of sum
            }
        }
        
        return maxLength;
    }
};