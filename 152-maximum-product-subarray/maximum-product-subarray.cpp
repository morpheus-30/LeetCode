class Solution {
public:
    int n;
    int ans ;
    void solve(int i,vector<int> &nums,pair<int,int> minmax){
        if(i==n){
            return;
        }
        int mini = minmax.first;
        int maxi = minmax.second;

        int newMin = min({nums[i], nums[i]*mini, nums[i]*maxi});
        int newMax = max({nums[i], nums[i]*mini, nums[i]*maxi});

        ans = max(ans,newMax);

        solve(i+1,nums,{newMin,newMax});


    }

    int maxProduct(vector<int>& nums) {
        pair<int,int> minmax = {nums[0],nums[0]};
        n = nums.size();
        ans = nums[0];
        solve(1,nums,minmax);
        return ans;
    }
};