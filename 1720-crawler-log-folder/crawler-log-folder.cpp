class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth= 0;
        for(auto x:logs){
            // cout<<depth<<endl;
            if(x=="../"){
                if(depth>0){
                    depth--;
                }
            }else if(x=="./"){
                continue;
            }else{
                depth++;
            }
        }
        return depth;
    }
};