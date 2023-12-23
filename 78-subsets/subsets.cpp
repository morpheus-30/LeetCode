class Solution {
public:

    void solve(vector<int> nums,vector<vector<int>> &ans,int index,vector<int> curr){
        if(index>=nums.size()){
            ans.push_back(curr);
            return;
        }
        solve(nums,ans,index+1,curr);
        curr.push_back(nums[index]);
        solve(nums,ans,index+1,curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums,ans,0,curr);
        return ans;
    }
};