class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int countZ = 0;
        for(auto x:nums){
            if(x==0){
                countZ++;
            }else{
                temp.push_back(x);
            }
        }
        int i=0;
        for(auto x:temp){
            temp[i] = x;
            i++;
        }
        while(countZ){
            temp.push_back(0);
            countZ--;
        }
        nums = temp;
    }
};