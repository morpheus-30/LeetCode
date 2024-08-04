class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int k=0;k<n-2;k++){
            if(k!=0&&nums[k]==nums[k-1]){
                continue;
            }
            int i=k+1;
            int j = n-1;
            while(i<j){
                
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[k],nums[i],nums[j]});
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
        
        return ans;
    }
};