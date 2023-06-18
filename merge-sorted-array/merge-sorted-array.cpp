class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        for(int i = 0;i<m;i++){
            temp.push_back(nums1[i]);
        }
        int i=0,j=0;
        int k=0;
        while(i<m&&j<n){
            nums1[k++] = temp[i]<nums2[j]?temp[i++]:nums2[j++];
        }
        while(j<n){
            nums1[k++] = nums2[j++];
        }
        while(i<m){
            nums1[k++] = temp[i++];
        }
    }
};