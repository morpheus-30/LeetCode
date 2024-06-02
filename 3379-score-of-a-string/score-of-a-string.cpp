class Solution {
public:
    int scoreOfString(string s) {
        int n  =s.size();
        int total = 0;
        for(int i=0;i<n-1;i++){
            total += abs(s[i+1]-s[i]);
        }
        return total;
    }
};