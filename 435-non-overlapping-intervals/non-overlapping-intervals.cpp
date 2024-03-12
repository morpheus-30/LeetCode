class Solution {
public:

    
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int ans=0;
        int end = intervals[0][1];
        for(int i=1;i<n;i++){
            // cout<<intervals[i][0]<<endl;
            if(intervals[i][0]<end){
               ans++;
            //    intervals.erase(intervals.begin()+i+1); 
            }else{
                end = intervals[i][1];
            }
        }
        return ans;
        
    }
};