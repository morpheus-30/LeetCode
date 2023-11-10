class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxC = 0;
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }else{
                maxC = max(maxC,count);
                count=0; 
            }
        }
        maxC = max(maxC,count);
        return maxC;
    }
};