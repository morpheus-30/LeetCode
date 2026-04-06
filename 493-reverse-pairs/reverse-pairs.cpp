class Solution {
public:


    void merge(vector<int> &nums,int l,int m,int r,int &ans){
        vector<int> temp;
        int i = l;
        int j = m+1;
        int y = j;
        for(int z=i;z<=m;z++){
           while(y<=r&&nums[z]>2LL*nums[y]){
            y++;
           }
            ans+= y-(m+1);
        }
        
        while(i<=m&&j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=r){
            temp.push_back(nums[j++]);
        }
        i=0;
        for(int ind = l;ind<=r;ind++){
            nums[ind] = temp[i++];
        }
    }

    void mergesort(vector<int> &nums, int l,int r,int &ans){
        if(l>=r){
            return;
        }
        int m = l+(r-l)/2;
        mergesort(nums,l,m,ans);
        mergesort(nums,m+1,r,ans);
        merge(nums,l,m,r,ans);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        mergesort(nums,0,n-1,ans);
        return ans;

    }
};  