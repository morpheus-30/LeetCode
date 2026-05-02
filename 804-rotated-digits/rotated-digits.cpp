class Solution {
public:
    int rotatedDigits(int n) {
        int mp[10] = {0,1,5,-1,-1,2,9,-1,8,6};

        int count = 0;
        for(int i=1;i<=n;i++){
            int num = i;
            bool isOtherPresent = false;
            bool isInvalidPresent = false;
            while(num>0){
                int rem = num%10;
                if(mp[rem] != -1 && mp[rem] != rem){
                    isOtherPresent = true;
                }else if(mp[rem] == -1){
                    isInvalidPresent = true;
                }

                num = num / 10;
            }

            if(isOtherPresent && !isInvalidPresent){
                count++;
            }
        }
        return count;


    }
};