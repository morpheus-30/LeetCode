class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int pos = -1,neg =-1;
        bool flagpos = false;
        bool flagneg = false;
        for(int i=0;i<n;i++){
            if(nums[i]>=0&&flagpos==false){
                pos = i;
                flagpos = true;
            }else if(nums[i]<0&&flagneg==false){
                neg = i;
                flagneg = true;
            }else if(flagpos==true&&flagneg==true){
                break;
            }
        }
        while(pos<n&&neg<n){
            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);
            pos++;
            neg++;
            while(neg<n&&nums[neg]>=0){
                neg++;
            }
            while(pos<n&&nums[pos]<0){
                pos++;
            }
        }
        while(neg<n){
            ans.push_back(nums[neg++]);
        }
        while(pos<n){
            ans.push_back(nums[pos++]);
        }
        return ans;
    }
};