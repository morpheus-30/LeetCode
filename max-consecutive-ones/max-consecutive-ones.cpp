class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0 ;
        int n= nums.size();
        int temp = 0;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(nums[i]==1){
                    temp++;
                    if(temp>ans){
                        ans=temp;
                    }
                }
            }

            if(nums[i]==1){
                temp++;
            }else{
                if(temp>ans){
                    ans = temp;
                    
                }
                temp = 0;
            }

        }   
        return ans;
    }
};