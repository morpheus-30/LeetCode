class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        if(k>arr.size()){
            return "";
        }   
        unordered_map<string,int> mp;
        for(auto x:arr){
           
                mp[x]++;
            
        }
        if(mp.size()<k){
            return "";
        }
        for(auto x:arr){
            if(mp[x]==1){
                k--;
                if(k==0){
                    return x;
                }
            }
        }
        return "";
    }
};