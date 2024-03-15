class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int count0 = 0;
        int n = nums.size();
        for(auto x:nums){
            if(x==0){
                count0++;
            }else{
                prod*=x;
            }
        }
        if(count0>=2){
            vector<int> ans(n,0);
            return ans;
        }
        vector<int> ans;
        for(auto x:nums){
            if(count0>0){
                if(x!=0){
                    ans.push_back(0);
                }else{
                    ans.push_back(prod);
                }
            }else{
                ans.push_back(prod/x);
            }
        }
        return ans;
    }
};