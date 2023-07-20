class Solution {
public:

    bool ifPalin(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        
        int startin=0;
        int maxL=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // cout<<i<<" "<<j<<endl;
                if(ifPalin(s,i,j)){
                    if(maxL<j-i+1){
                        startin = i;
                        maxL=j-i+1;
                    }
                }
            }
        }
        return s.substr(startin,maxL);
    }
};