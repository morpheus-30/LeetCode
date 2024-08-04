class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int k=0;k<n-2;k++){
            int i=k+1;
            int j = n-1;
            while(i<j){
                
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.insert({nums[k],nums[i],nums[j]});
                    i++;
                    j--;
                    while(i<j&&nums[i-1]==nums[i]){
                        i++;
                    }
                    while(i<j&&nums[j+1]==nums[j]){
                        j--;
                    }
                }else if(nums[i]+nums[j]+nums[k]<0){
                    i++;
                }else{
                    j--;
                }
            }
        }
        vector<vector<int>> ans2(ans.begin(),ans.end());
        return ans2;
    }
};