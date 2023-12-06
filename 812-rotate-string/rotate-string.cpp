class Solution {
public:
    bool rotateString(string s, string goal) {
        //step1 find number of rotations
        //step2 compare the whole string
        if(s.size()!=goal.size()){
            return false;
        }
        bool flag = false;
        goal = goal+goal;
        int lastJ = -1;
        int i = 0;
        int j = 0;
        int n = s.size();
        while(i<n&&j<2*n){
            if(s[i]==goal[j]){
                if(flag==false){
                    flag = true;
                    lastJ = j;
                }
                i++;
                j++;
            }else{
                if(flag==true){
                    j = lastJ;
                    flag = false;
                }
                j++;
                i=0;
            }
        }
        if(i==n){
            return true;
        }
        return false;
    }
};