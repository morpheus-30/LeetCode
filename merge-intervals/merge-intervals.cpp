class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),
          intervals.end(),
          [] (const vector<int> &a, const vector<int> &b)
          {
              return a[0] < b[0];
          });
        if(n==1){
            return intervals;
        }
        for(int i = 0 ; i < n-1;i++){
                if(intervals[i][1]>=intervals[i+1][0]&&intervals[i+1][1]>=intervals[i][0]){
                    int minInt = intervals[i][0]<intervals[i+1][0]?intervals[i][0]:intervals[i+1][0];
                    int maxInt = intervals[i+1][1]>intervals[i][1]?intervals[i+1][1]:intervals[i][1];
                    intervals[i+1][0] = minInt;
                    intervals[i+1][1] = maxInt;
                    intervals[i][0] = -1;
                    intervals[i][1] = -1;
            }
        }   
        vector<vector<int>> ans;
        for(auto x:intervals){
            if(x[0]>=0){
                ans.push_back(x);
            }
        }
        return ans;
    }
};