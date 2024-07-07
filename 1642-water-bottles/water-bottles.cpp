class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int currFilled = numBottles;
        int currEmpty = 0;
        int ans = 0;
        while(currEmpty>0||currFilled>0){
            cout<<currEmpty<<":"<<currFilled<<endl;
            if(currFilled){
                ans+=currFilled;
                currEmpty+=currFilled; 
                currFilled = 0;
            }else if(currEmpty){
                if(currEmpty<numExchange){
                    break;
                }
                currFilled+=(currEmpty/numExchange);
                currEmpty = currEmpty%numExchange;
            }
        }
        return ans;
    }
};