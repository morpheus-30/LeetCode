#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int atmostk(vector<int> &nums,int k){

        int sum = 0;
        int count = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while(right<n){
            sum+=nums[right];
            while(sum>k&&left<=right){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atmostk(nums,goal)-atmostk(nums,goal-1);
    }
};