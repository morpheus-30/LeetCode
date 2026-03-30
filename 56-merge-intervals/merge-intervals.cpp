class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        while(i<intervals.size()){
            if(ans.size()==0){
                ans.push_back(intervals[i]);
                i++;
                continue;
            }
            vector<int> next = intervals[i];
            vector<int> &curr = ans[ans.size()-1];
            if(curr[1]>=next[0]){
                curr[1] = max(curr[1],next[1]);
                i++;
                continue;
            }
            ans.push_back(next);
            i++;
        }
        return ans;
    }
};