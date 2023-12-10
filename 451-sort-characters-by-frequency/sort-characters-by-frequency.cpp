class Solution {
public:

    bool static cmp(const pair<char,int> &a,const pair<char,int> &b){
        return (a.second>b.second);
    }

    string frequencySort(string s) {
        ///brute -> loop -> count-> map -> loop map
        unordered_map<char,int> mp;
        for(auto x:s) mp[x]++;
        vector<pair<char,int>> v;
        for(auto x:mp) v.push_back(x);
        sort(v.begin(),v.end(),cmp);
        string ans = "";
        for(auto &x:v){
            while(x.second!=0){
                ans+=x.first;
                x.second--;
            }
        }
        return ans;
    }
};