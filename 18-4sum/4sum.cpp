class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i!=0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                long long temp = (nums[i]+nums[j]);

                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum2 = nums[k]+nums[l];
                    if(sum2+temp==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<n&&nums[k-1]==nums[k]){
                            k++;
                        }
                        while(l>k&&nums[l+1]==nums[l]){
                            l--;
                        }
                    }else if(sum2+temp<target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};