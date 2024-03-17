class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        for(int i=0;i<n;i++){
            if(i-1>=0&&ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(i+1<n&&ratings[i]>ratings[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);
        }
        return sum;

                

    }
};