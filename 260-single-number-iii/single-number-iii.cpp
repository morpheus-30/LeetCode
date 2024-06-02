class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = 0;
        for(auto x:nums){
            xors^=x;
        }
        int setbit = xors&-(unsigned int)xors;
        int a=0,b=0;
        for(auto x:nums){
            if(x&setbit){
                a^=x;
            }else{
                b^=x;
            }
        }
        return {a,b};
    }
};