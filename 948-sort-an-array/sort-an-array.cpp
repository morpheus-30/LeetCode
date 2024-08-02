class Solution {
public:

    void merge(vector<int> &nums,int l,int mid,int r){
        if(l>=r){
            return;
        }
        int left = l;
        int right = mid+1;
        vector<int> temp;
        while(right<=r&&left<=mid){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
             temp.push_back(nums[left++]);
        }
        while(right<=r){
            temp.push_back(nums[right++]);
        }
        for(int i=l;i<=r;i++){
            nums[i] = temp[i-l];
        }
    }

    void mergeSort(vector<int> &nums,int l,int r){
        if(l>=r){
            return;
        }
        int mid = (l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};