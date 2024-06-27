class Solution {   // STRIVER'S DP APPROACH || TC = 0(N)  SC = 0(1) 
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxprofit = 0;
        int mini =INT_MAX; 

         for( int i =0 ; i< n ; i++){
              int cost = prices[i]- mini;
              maxprofit = max(  maxprofit , cost);
              mini = min( mini , prices[i] );
         }

         return maxprofit;
    }
};