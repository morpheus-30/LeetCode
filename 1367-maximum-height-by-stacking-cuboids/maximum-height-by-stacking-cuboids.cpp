class Solution {
public:

    bool check(vector<int> a,vector<int> b){
        if(b[0]<=a[0]&&b[1]<=a[1]&&b[2]<=a[2]){
            return true;
        }else{
            return false;
        }
    }

    int solve(vector<vector<int>>& nums){
        int n = nums.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int currIndex = n-1;currIndex>=0;currIndex--){
            for(int prevIndex = currIndex-1;prevIndex>=-1;prevIndex--){
                int take = 0;
                if(prevIndex==-1||check(nums[currIndex],nums[prevIndex])){
                    take = nums[currIndex][2]+next[currIndex+1];
                }
                int notTake = next[prevIndex+1];
                curr[prevIndex+1] = max(take,notTake);
            }
            next = curr;
        }
        return next[0]; 
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &dim:cuboids){
            sort(dim.begin(),dim.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return solve(cuboids);
    }
};