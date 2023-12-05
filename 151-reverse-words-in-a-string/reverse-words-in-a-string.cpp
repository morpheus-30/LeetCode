class Solution {
public:
    string reverseWords(string s) {
        string totalString = "";
        string currW = "";
        for(int i=0;i<s.length();i++){
            // cout<<totalString<<endl;
            if(s[i]==' '){
                if(currW!=""){
                    if(totalString!=""){
                        totalString = currW+" "+totalString;
                    }else{
                        totalString = currW;
                    }
                }
                currW = "";
                continue;
            }else{
                currW+=s[i];
            }
        }
        if(currW!=""){
            if(totalString!=""){
                totalString = currW+" "+totalString;
            }else{
                totalString = currW;
            }
        }
        return totalString;

    }
};