class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> hor(n,1);
        vector<int> vert(m,1);

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    vert[i] = 0;
                    hor[j] = 0;
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            if(hor[i]==0){
                for(int k = 0;k<m;k++){
                    matrix[k][i] = 0;
                }
            }
        }
        for(int i = 0;i<m;i++){
            if(vert[i]==0){
                for(int k = 0;k<n;k++){
                    matrix[i][k] = 0;
                }
            }
        }
        
    }
};