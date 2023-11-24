class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = INT_MAX;
        int n = arr.size();
        int count = k;
        int i = 1;
        int index = 0;
        while(count>0&&index<n){
            if(arr[index]!=i){
                count--;
                ans = i;
                i++;
            }else{
                i++;
                index++;
            }
        }
        if(count!=0){
            for(int k = 0;k<count;k++){
                ans = i;
                i++;
            }
        }
        return ans;
    }
};