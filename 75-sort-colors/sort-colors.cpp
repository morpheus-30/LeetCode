class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        for(int i=0;i<=high;){
            cout<<nums[i]<<nums[low]<<nums[high]<<endl;
            if(nums[i]==0){
                swap(nums[low],nums[i]);
                low++;
            }else if(nums[i]==2){
                swap(nums[i],nums[high]);
                high--;
                continue;
            }
            i++;
        }
    }
};