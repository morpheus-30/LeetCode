class Solution {
public:
    bool rotateString(string s, string goal) {
        //brute force???
        if(s.size() != goal.size()){
            return false;
        }

        int n = s.size();

        for(int i=0;i<n;i++){
            int j = 0;
            int k = i;

            while(j<n && s[(k)%n] == goal[j]){
                j++;
                k++;
            }
            if(j==n){
                return true;
            }
        }
        return false;


    }
};