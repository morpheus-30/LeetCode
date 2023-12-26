class Solution {
public:

    void solve(vector<int>& candidates, int target,int index,vector<int> curr,vector<vector<int>> &ans){
        if(target==0){
            sort(curr.begin(),curr.end());
            ans.push_back(curr);
            return;
        }   
        if(target<0||index==candidates.size()){
            return;
        }
        curr.push_back(candidates[index]);
        solve(candidates,target-candidates[index],index+1,curr,ans);
        curr.pop_back();
        while(index+1<candidates.size()&&candidates[index]==candidates[index+1]){
            index++;
        }
        solve(candidates,target,index+1,curr,ans);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,curr,ans);
        // vector<vector<int>> ansf(ans.begin(),ans.end());
        return ans;
    }
};