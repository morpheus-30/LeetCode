class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        int n = nums.size();
        if(n==0){
            return n;
        }
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        int maxC = 1;
        for(auto it:nums){
            if(mp.find(it-1)==mp.end()){
                int x = it;
                int count = 1;
                while(mp.find(x+1)!=mp.end()){
                    count++;
                    x++;
                }
                maxC = max(maxC,count);
            }
        }
        return maxC;

    }
};