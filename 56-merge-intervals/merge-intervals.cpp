class Solution {
public:


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(intervals[i]);
            }
            if(ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                vector<int> tempI = ans.back();
                ans.pop_back();
                tempI[0] = min(tempI[0],intervals[i][0]);
                tempI[1] = max(tempI[1],intervals[i][1]);
                ans.push_back(tempI);
            }
        }
        return ans;
    }
};