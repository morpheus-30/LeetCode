class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int currMin = nums[0];
        int currMax = nums[0];

        int n = nums.size();

        for(int i=1;i<n;i++){
            int temp = currMin * nums[i];
            currMin = min({nums[i],nums[i]*currMin,nums[i]*currMax});
            currMax = max({nums[i],temp,nums[i]*currMax});
            ans = max(currMax,ans);

        }
        return ans;
    }
};

// class Solution {
// public:
//     int n;
//     int ans ;
//     void solve(int i,vector<int> &nums,pair<int,int> minmax){
//         if(i==n){
//             return;
//         }
//         int mini = minmax.first;
//         int maxi = minmax.second;

//         int newMin = min({nums[i], nums[i]*mini, nums[i]*maxi});
//         int newMax = max({nums[i], nums[i]*mini, nums[i]*maxi});

//         ans = max(ans,newMax);

//         solve(i+1,nums,{newMin,newMax});
//     }

//     int maxProduct(vector<int>& nums) {
//         pair<int,int> minmax = {nums[0],nums[0]};
//         n = nums.size();
//         ans = nums[0];
//         solve(1,nums,minmax);
//         return ans;
//     }
// };

