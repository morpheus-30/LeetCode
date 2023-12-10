class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;
        for(auto &x:s){
            if(x=='('){
                count++;
            }else if(x==')'){
                maxCount = max(maxCount,count);
                count--;
            }
        }
        return maxCount;
    }
};