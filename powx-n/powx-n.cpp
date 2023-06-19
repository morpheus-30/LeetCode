class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(x==1||x==-1){
            if(x==-1&&n%2!=0){
                ans = -1;
            }
            return ans;
        }
        if(n>=0){
            for(long long i = 0;i<n;i++){
            ans*=x;
            }
        }else{
            for(long long i = 0;i<abs(n);i++){
                ans = ans/x;
                if(ans<0.00001){
                    return 0.0000;
                }
            }
        }
        return ans;
    }
};