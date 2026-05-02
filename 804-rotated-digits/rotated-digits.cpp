class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int,int> mp;
        mp[0] = 0;
        mp[1] = 1;
        mp[2] = 5;
        mp[3] = -1;
        mp[4] = -1;
        mp[5] = 2;
        mp[6] = 9;
        mp[7] = -1;
        mp[8] = 8;
        mp[9] = 6;

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