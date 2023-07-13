class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> temp;
        for(auto x:nums2){
            temp.push(x);
        }
        stack<int> temp2 = temp;
        for(int i=0;i<nums1.size();i++){
            int toPush = -1;
            while(temp2.top()!=nums1[i]){
                if(temp2.top()>nums1[i]){
                    toPush = temp2.top();
                }
                temp2.pop();
                
            }
            temp2 = temp;
            ans.push_back(toPush);
        }
        return ans;
    }
};