class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int req = (m+n+1)/2;

        int low = max(0,req-n);
        int high = min(req,m);

        while(low<=high){
            int rfA = low + (high-low)/2;
            int rfB = req-rfA;

            int leftA  = (rfA == 0) ? INT_MIN : nums1[rfA-1];
            int rightA = (rfA == m) ? INT_MAX : nums1[rfA];

            int leftB  = (rfB == 0) ? INT_MIN : nums2[rfB-1];
            int rightB = (rfB == n) ? INT_MAX : nums2[rfB];

            if(leftA <= rightB && leftB <= rightA){
                if((m+n)%2==0){
                    return (max(leftA,leftB) + min(rightA,rightB)) / 2.0;
                }else{
                    return max(leftA,leftB);
                }
            }
            else if(leftA > rightB){
                high = rfA - 1;
            }
            else{
                low = rfA + 1;
            }
        }
        return -1;
    }
};