class Solution {
public:

    int solve(vector<int>& arr, int diff){
        int n = arr.size();
        int ans = 0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int temp = arr[i] - diff;
            int tempans = 0;
            if(map.count(temp)){
                tempans = map[temp];
            }
            map[arr[i]] = 1+tempans;
            ans = max(ans,map[arr[i]]);
        }
        return ans;

        
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        return solve(arr,difference);
    }
};