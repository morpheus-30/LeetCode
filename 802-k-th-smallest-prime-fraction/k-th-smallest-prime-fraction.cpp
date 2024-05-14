class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if(arr.size()==2){
            return arr;
        }
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double fraction = double(arr[i])/double(arr[j]);
                
                pq.push({fraction,{i,j}});
            }
        }
        vector<int> ans(2,-1);
        while(k--){
            auto top = pq.top();
            ans[0] = arr[top.second.first];
            ans[1] = arr[top.second.second];
            pq.pop();
        }
        return ans;
        
    }
};