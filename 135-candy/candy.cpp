class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> toffee;
        int n = ratings.size();
        int ans = n;
        for(int i=0;i<n;i++){
            pair<int,int> temp = {ratings[i],i};
            pq.push(temp);
            toffee.push_back(1);
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int rating = top.first;
            cout<<rating<<" "<<index<<endl;
            int index = top.second;
            int left = 0,right = 0;
            if(index-1>=0&&ratings[index]>ratings[index-1]){
                left = toffee[index-1];
            }
            if(index+1<n&&ratings[index]>ratings[index+1]){
                right = toffee[index+1];
            }

            int maxi = max(left,right);
            if(maxi!=0){
                ans+=(maxi-toffee[index]+1);
                toffee[index] = maxi+1;

            }
        }
        return ans;
    }
};