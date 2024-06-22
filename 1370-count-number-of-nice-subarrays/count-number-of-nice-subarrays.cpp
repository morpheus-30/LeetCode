class Solution {
public:

    int atmostk(vector<int> &nums,int k){
        int left = 0;
        int currOdd = 0;
        int ans = 0;
        int n = nums.size();
        for(int right=0;right<n;right++){
            if(nums[right]%2!=0){
                currOdd++;
            }
            while(left<=right&&currOdd>k){
                if(nums[left]%2==1){
                    currOdd--;
                }
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);

    }
};