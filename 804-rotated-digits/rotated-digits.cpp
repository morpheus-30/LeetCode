class Solution {
public:
    int mp[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
    int isGood(int num,vector<int> &dp) {
        if(dp[num] != -1){
            return dp[num];
        }
        if (num == 0) {
            return dp[num] = 0;
        }
        int remain = isGood(num/10,dp);
        int dig_chk = -1;
        int rem = num % 10;
        if(mp[rem] == -1){
            dig_chk = 2;
        }else if(mp[rem] != rem){
            dig_chk = 1;
        }else if(mp[rem] == rem){
            dig_chk = 0;
        }

        if(remain == 0 && dig_chk == 0){
            return dp[num] = 0;
        }else if(remain == 2 || dig_chk == 2){
            return dp[num] = 2;
        }else{
            return dp[num] = 1;
        }
    }

    int rotatedDigits(int n) {
        
        vector<int> dp(n + 1, -1);

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if(isGood(i,dp)==1){
                count++;
            }
        }
        return count;
    }
};