class Solution {
public:

    void solve(vector<int>& candidates, int target,int index,vector<int> curr,vector<vector<int>> &ans){
        if(target==0){
            // sort(curr.begin(),curr.end());
            ans.push_back(curr);
            return;
        }   
        // if(target<0||index==candidates.size()){
        //     return;
        // }
        for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i-1]==candidates[i]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,curr,ans);
            curr.pop_back();
        }

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