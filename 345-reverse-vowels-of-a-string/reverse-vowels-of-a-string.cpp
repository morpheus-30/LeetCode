class Solution {
public:
    string reverseVowels(string s) {
        string ans = s;
        int n = s.size();
        if(n==1){
            return s;
        }
        string vs = "";
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                vs+=s[i];
                s[i] = '$';
            }
        }
        if(vs==""){
            return s;
        }
        reverse(vs.begin(),vs.end());
        int index = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='$'){
                s[i] = vs[index];
                index++;
            }
        }
        return s;
    }
};