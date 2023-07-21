class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string start = strs[0];
        string end = strs[strs.size()-1];
        string toBeReturned = "";
        for(int i=0;i<start.size()&&i<end.size();i++){
            if(start[i]==end[i]){
                toBeReturned += start[i];
            }else{
                break;
            }
        }
        return toBeReturned;
    }
};