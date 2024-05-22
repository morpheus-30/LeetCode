class Solution {
public:

    void solve(vector<int> &nums,vector<int> currvec,set<vector<int>> &ans,int index){
        ans.insert(currvec);
        if(index>=nums.size()){
            return;
        }
        //exclude   
        solve(nums,currvec,ans,index+1);
        //include
        currvec.push_back(nums[index]);
        solve(nums,currvec,ans,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> subsets;
        
        vector<int> currvec;
        solve(nums,currvec,subsets,0);
        vector<vector<int>> ans(subsets.begin(),subsets.end());
        return ans;

    }
};