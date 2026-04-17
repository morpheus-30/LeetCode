class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int n = g.size();
        int m = s.size();
        int ans = 0;
        int j = 0,i=0;
        while(i<n&&j<m){
            if(g[i] <= s[j]){
                i++;
                ans++;
            }
            j++;
        }

        return i;
        
    }
};