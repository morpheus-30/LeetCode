class Solution {
public:

    int minCount(vector<int>&nums,int count){
        int left = 0;
        int n = nums.size();
        int ans = INT_MAX;
        int curr = 0;
        for(int right = 0;right<n;right++){
            if(nums[right]==1){
                curr++;
            }
            while(right-left>=count){
                if(nums[left]==1){
                    curr--;
                }
                left++;
            }
            ans = min(ans,count-curr);
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int count1  = 0;
        for(auto x:nums){
            
        }
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count1++;
            }
            nums.push_back(nums[i]);
        }
        return minCount(nums,count1);
    }
};