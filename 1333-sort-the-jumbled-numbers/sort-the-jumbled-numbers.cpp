class Solution {
public:
    

    int convert(int num,vector<int> &mapping){
        string numS = to_string(num);
        string ret = "";
        
        for(int i=0;i<numS.size();i++){
            ret+= to_string(mapping[numS[i]-'0']);
        }
        return stoi(ret);
    }

    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> ans;

        for(int i=0;i<nums.size();i++){
            ans.push_back({convert(nums[i],mapping),i});
        }

        sort(ans.begin(),ans.end(),cmp);
        vector<int> aans;
        for(auto x:ans){
            aans.push_back(nums[x.second]);
        }
        return aans;
    }
};