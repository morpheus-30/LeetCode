#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int atmostk(vector<int> &nums,int k){
        int left = 0;
        int right = 0;
        int cnt = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        while(right<n){
            mp[nums[right]]++;
            while(mp.size()>k&&left<=right){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
    }
};