class Solution {
public:

    int arrays(vector<int> &nums,int mini){
        int number = 1;
        int currSum = 0;
        for(auto x:nums){
            if(x>mini){
                return INT_MAX;
            }
            if(currSum+x<=mini){
                currSum+=x;
            }else{
                number++;
                currSum = x;
            }
        }
        return number;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = INT_MAX;
        int high = 0;
        for(auto x:nums){
            low = min(low,x);
            high +=x;
        }
        while(low<=high){
            int mid = (low+high)/2;
            int no = arrays(nums,mid);
            if(no>k){
                low = mid+1;;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};