#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1!=n2){
            return -1;
        }
        unordered_map<char,int> tmap;
        for(auto x:t){
            tmap[x]++;
        }
        for(auto x:s){
            if(tmap.find(x)!=tmap.end()){
                tmap[x]--;
                if(tmap[x]==0){
                    tmap.erase(x);
                }
            }
        }
        int ans = 0;
        for(auto x:tmap){
            ans+=x.second;
        }
        return ans;
    }
};