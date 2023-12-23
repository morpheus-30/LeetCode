class Solution {
public:
    double myPow(double x, int n) {
        if(x==1||x==0||x==-1){
            if(x==1||x==0){
                return x;
            }else{
                return n%2==0?1:-1;
            }
        }
        long long N = n;
        if(N==0){
            return 1;
        }
        if(N==1){
            return x;
        }
        if(N<0){
            x=1/x;
            N = -N;
        }
        if(N%2==0){
            return myPow(x*x,N/2);
        }else{
            return x*myPow(x*x,N/2);
        }

    }
};