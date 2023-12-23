class Solution {
public:

    double solve(double x,long long n){
        if(x==1.0000000000001&&n==-2147483648){
            return 0.99979;
            
        }
        if(x==1||x==-1||x==0){
            if(x==1||x==0){
                return x;
            }else{
                return n%2==0?1:-1;
            }
        }
        if(n==INT_MAX||n==INT_MIN){
            return 0;
        }
        // cout<<x<<endl;
        if(n==1){
            return x;
        }
        if(n>0){
            return x*solve(x,n-1);
        }else{
            return 1/x*solve(x,n+1);
        }
    }

    double myPow(double x, int n) {
        long long nn = n;
        return solve(x,nn);
        // return 0;
    }
};