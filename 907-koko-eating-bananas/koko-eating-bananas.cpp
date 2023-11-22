class Solution {
public:

    int totalHours(vector<int>& piles, int h,int hourly){
        double totalH = 0;
        for(auto x:piles){
            totalH+=ceil((double)(x)/(double)(hourly));
        }
        return totalH<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int high = piles[n-1];
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(totalHours(piles,h,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};