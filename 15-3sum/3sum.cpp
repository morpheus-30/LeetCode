class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int j,k;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=0&&nums[i]==nums[i-1]){
                continue;
            }
            j = i+1;
            k = n-1;
            while(j<k){
                if((nums[i]+nums[j]+nums[k])==0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k&&nums[j-1]==nums[j]){
                        j++;
                    }
                    while(k>j&&nums[k]==nums[k+1]){
                        k--;
                    }
                }else if((nums[i]+nums[j]+nums[k])<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};