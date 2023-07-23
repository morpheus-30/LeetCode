class Solution {
public:
    bool isAnagram(string s, string t) {
        long s1 = 0;
        long t1 = 0;
        int i = s.size()-1;
        for(auto x:s){
            s1 = s1 + (x+x*x+x*x*x);
            i--;
        }
        for(auto x:t){
            t1 = t1 + (x+x*x+x*x*x);
            i--;
        }
        cout<<t1<<" "<<s1;
        return t1==s1;
    }
};