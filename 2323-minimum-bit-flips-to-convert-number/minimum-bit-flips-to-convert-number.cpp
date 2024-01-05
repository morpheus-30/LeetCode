class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start^goal;
        int c = 0;
        while(res){
            if(res&1==1){
                c++;
            }
            res>>=1;
        }
        return c;
    }
};