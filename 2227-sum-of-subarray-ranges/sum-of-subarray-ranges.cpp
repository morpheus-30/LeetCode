class Solution {
public:

    long long sumSubarrayMins(vector<int>& arr) {
      long long sum=0;
      long long sumc= 0;
      deque<pair<long long,long long>>dq;
      for(long long i=0;i<arr.size();i++){
          long long popped= 1;
          while(dq.size()&& dq.back().first >= arr[i]){
              popped+= dq.back().second;
              sumc-= (dq.back().first * dq.back().second);
              dq.pop_back();
          }
          sum+= sumc;
          dq.push_back({arr[i],popped});
          sum= (sum + arr[i]*popped);
          sumc+= arr[i]*popped;
      }  
      return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
      long long sum=0;
      long long sumc= 0;
      deque<pair<long long,long long>>dq;
      for(long long i=0;i<arr.size();i++){
          long long popped= 1;
          while(dq.size()&& dq.back().first <= arr[i]){
              popped+= dq.back().second;
              sumc-= (dq.back().first * dq.back().second);
              dq.pop_back();
          }
          sum+= sumc;
          dq.push_back({arr[i],popped});
          sum= (sum + arr[i]*popped);
          sumc+= arr[i]*popped;
      }  
      return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};