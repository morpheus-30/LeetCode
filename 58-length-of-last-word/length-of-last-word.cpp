class Solution {
public:
    int lengthOfLastWord(string s) {
        int pols = -1;
        int n = s.size();
        int pola = n-1;
        while(pola>=0&&s[pola]==' '){
            pola--;
        }
        cout<<s[pola]<<endl;
        for(int i=0;i<=pola;i++){
            if(s[i]==' '){
                pols = i;
            }
            
        }
        cout<<pola<<pols;
        if(pols==-1){
            return pola+1;
        }
        return pola-pols;
    }
};