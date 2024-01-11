class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap;
        unordered_map<char,int> smap;
        for(auto x:t){
            tmap[x]++;
        }
        
        string ans = s+t;
        int left = 0;
        int right = 0;
        int n = s.size();
        while(right<n){
            smap[s[right]]++;
            while(left<=right){
                if(smap[s[left]]>tmap[s[left]]){
                    smap[s[left]]--;
                    if(smap[s[left]]==0){
                        smap.erase(s[left]);
                    }
                    left++;
                }else{
                    break;
                }
            }
            int iftrue = 0;
            for(auto x:tmap){
                if(smap[x.first]>=x.second){
                    iftrue++;
                }
            }
            if(iftrue==tmap.size()){
                ans = ans.size()<right-left+1?ans:s.substr(left,right-left+1);
                // cout<<s.substr(left,right-left+1)<<endl;
                // cout<<ans.size()<<" "<<right-left+1<<endl;
            }
            right++;
        }
        if(ans==s+t){
            return "";
        }
        return ans;
    }
};