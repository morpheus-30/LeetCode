class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        pair<int,int> one = {0,INT_MAX};
        pair<int,int> two = {0,INT_MAX};

        for(int i=0;i<nums.size();i++){
            if(one.second==nums[i]){
                one.first++;
            }else if(two.second==nums[i]){
                two.first++;
            }else if(one.first == 0){
                one.second = nums[i];
                one.first++;
            }else if(two.first==0){
                two.second = nums[i];
                two.first++;
            }else{
                one.first--;
                two.first--;
            }

        }
        vector<int> ans;
        one.first=0;two.first=0;
        for(auto x:nums){
            if(x==one.second){
                one.first++;
            }
            if(x==two.second){
                two.first++;
            }
        }
        if(one.first>nums.size()/3){
            ans.push_back(one.second);
        }
        if(two.first>nums.size()/3){
            ans.push_back(two.second);
        }
        return ans;


    }
};