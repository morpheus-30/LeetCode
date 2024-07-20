class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();

        if(cols==1&&rows==1){
            return {{rowSum[0]}};
        }
        if(rows==1){
            return {colSum};
        }
        if(cols==1){
            vector<vector<int>> ans;
            for(auto x:rowSum){
                ans.push_back({x});
            }
            return ans;
        }

        vector<vector<int>> ans(rows,vector<int>(cols,0));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans[i][j] = min(colSum[j],rowSum[i]);
               rowSum[i]-=ans[i][j];
               colSum[j]-=ans[i][j];
                // while(rowSum[i]>0&&colSum[j] >0){
                //     ans[i][j]++;
                //     rowSum[i]--;
                //     colSum[j]--;
                // }
            }
        }
        return ans;


    }
};