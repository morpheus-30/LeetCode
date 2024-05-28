class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int maxLength = 0;
        int left = 0;
        int currCost = 0;
        for(int right=0;right<n;right++){
            currCost+=abs(s[right]-t[right]);
            while(left<=right&&currCost>maxCost){
                currCost-=abs(s[left]-t[left]);
                left++;
            }
            maxLength = max(maxLength,right-left+1);
        }
        return maxLength;
    }
};