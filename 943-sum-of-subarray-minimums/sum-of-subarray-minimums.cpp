class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      int mod= (1e9+7);
      long sum=0;
      long sumc= 0;
      deque<pair<int,int>>dq;
      for(int i=0;i<arr.size();i++){
          int popped= 1;
          while(dq.size()&& dq.back().first >= arr[i]){
              popped+= dq.back().second;
              sumc-= (dq.back().first * dq.back().second);
              dq.pop_back();
          }
          sum+= sumc;
          dq.push_back({arr[i],popped});
          sum= (sum + arr[i]*popped)% mod;
          sumc+= arr[i]*popped;
      }  
      return sum;
    }
};