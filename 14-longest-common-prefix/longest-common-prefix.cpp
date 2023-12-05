class Solution {
public:

    string compareMera(string&a,string&b){
        int i = 0,j=0;
        string toRet = "";
        int n1 = a.length(),n2 = b.length();
        while(i<n1&&j<n2){
            // cout<<toRet<<endl;
            if(a[i]==b[j]){
                toRet += a[i];
                i++;
                j++;
            }else{
                return toRet;
            }
        }
        return toRet;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        string ans = "";
        string reference = strs[0];
        for(int i=1;i<strs.size();i++){
            string com = compareMera(reference,strs[i]);
            cout<<com<<endl;
            if(com==""){
                return com;
            }else{
                if(ans!=""){
                    ans = compareMera(ans,com);
                }else{
                    ans = com;
                }
            }
        }
        return ans;
    }
};