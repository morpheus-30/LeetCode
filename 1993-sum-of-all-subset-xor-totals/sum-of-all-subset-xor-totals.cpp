class Solution {
public:

    void solve(vector<int> &nums,int currxor,int &totalxor,int index){
        if(index>=nums.size()){
         totalxor+=currxor;
            return;
        }
        //exclude   
        solve(nums,currxor,totalxor,index+1);
        //include
        currxor^=nums[index];
        solve(nums,currxor,totalxor,index+1);
    }

    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        solve(nums,0,ans,0);
        return ans;

    }
};