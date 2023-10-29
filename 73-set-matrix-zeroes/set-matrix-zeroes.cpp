class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k = 0;k<max(m,n);k++){
                        if(k<m&&matrix[k][j]!=0){
                            matrix[k][j] = -69;
                        }
                        if(k<n&&matrix[i][k]!=0){
                            matrix[i][k] = -69;
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==-69){
                    matrix[i][j]=0;
                }
            }
        }
    }
};