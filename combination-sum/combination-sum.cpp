class Solution {
public:

    void solve(int ind,int target,vector<int> &ds,vector<vector<int>> &ans,vector<int> &arr){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            solve(ind, target-arr[ind],ds,ans,arr);
            ds.pop_back();
        }
        solve(ind+1,target,ds,ans,arr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,ds,ans,candidates);
        vector<vector<int>> vc(ans.begin(), ans.end());
        return vc;

        
       

    }
};