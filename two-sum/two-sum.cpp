class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            num[nums[i]] = i;
        }
        for(int i = 0;i<nums.size();i++){
            int anotherNo = target - nums[i];
            if(num[anotherNo]&&i!=num[anotherNo]){
                ans.push_back(num[anotherNo]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};