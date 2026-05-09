class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;
        if(k==0){
            return;
        }

        int ind = n - k;
        int i = 0;
        
        vector<int> cp = nums;
        while(i<n){
            cp[i] = nums[ind];
            i++;
            ind = (ind+1) % n;
        }
        
        nums = cp;

    }
};