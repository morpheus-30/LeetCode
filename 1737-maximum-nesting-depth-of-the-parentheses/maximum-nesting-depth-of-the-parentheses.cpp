class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;
        for(auto x:s){
            if(x=='('){
                count++;
                maxCount = max(maxCount,count);
            }else if(x==')'){
                count--;
            }
        }
        return maxCount;
    }
};