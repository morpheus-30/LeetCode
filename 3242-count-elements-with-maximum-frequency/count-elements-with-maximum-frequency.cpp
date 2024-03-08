class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int noofele = 0;
        int maxfreq = 0;
        for(auto x:nums){
            mp[x]++;
            if(maxfreq<mp[x]){
                maxfreq = mp[x];
                noofele = 1;
            }else if(maxfreq==mp[x]){
                noofele++;
            }
        }
        return noofele*maxfreq;

        
    }
};