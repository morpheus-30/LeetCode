class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        sort(intervals.begin(),intervals.end());
        while(i<intervals.size()-1){
            vector<int> next = intervals[i+1];
            vector<int> curr = intervals[i];
            if(curr[1]>=next[0]){
                intervals[i][1] = max(curr[1],next[1]);
                intervals.erase(intervals.begin()+i+1);
                continue;
            }
            i++;
        }
        return intervals;
    }
};