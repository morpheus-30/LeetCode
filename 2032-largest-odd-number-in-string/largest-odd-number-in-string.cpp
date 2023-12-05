class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.length()-1;i>=0;i--){
            // cout<<num[i]<<endl;
            if((num[i]-48)%2==1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};