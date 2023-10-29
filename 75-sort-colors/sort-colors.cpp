class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        for(auto x:nums){
            if(x==0){
                c0++;
            }
            if(x==1){
                c1++;
            }
            if(x==2){
                c2++;
            }
        }
        int i = 0;
        while(c0){
            nums[i] = 0;
            i++;
            c0--;
        }
        while(c1){
            nums[i] = 1;
            i++;
            c1--;
        }
        while(c2){
            nums[i] = 2;
            i++;
            c2--;
        }
    }
};