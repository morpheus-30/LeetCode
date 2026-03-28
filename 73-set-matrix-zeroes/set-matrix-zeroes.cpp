class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ver = -1;
        int n = matrix.size();
        int m = matrix[0].size();


        if(matrix[0][0] == 0){
            ver = 0;
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j] == 0){
                matrix[0][0] = 0;
            }
        }

        for(int i=1;i<n;i++){
            if(matrix[i][0] == 0){
                cout<<matrix[i][0]<<endl;
                ver = 0;
            }
        }


        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0]  = 0;
                }
            }
        }

        //evluating everything other than horizontal and vertical
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        //horizontal
        if(matrix[0][0] == 0){
            for(int j=0;j<m;j++){
                matrix[0][j] = 0;
            }
        }
        if(ver == 0){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }

        cout<<ver<<matrix[0][0]<<endl;
    }
};