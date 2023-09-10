class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &grid,int m,int n){
        vector<int> delr={0,-1,0,1};
        vector<int> delc = {1,0,-1,0};
        grid[row][col] = 69;
        for(int i=0;i<4;i++){
            int nrow =row+ delr[i];
            int ncol=col+delc[i];
            if(nrow>=0&&ncol>=0&&nrow<m&&ncol<n&&grid[nrow][ncol]==1){
                cout<<nrow<<" "<<ncol<<endl;
                dfs(nrow,ncol,grid,m,n);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&(i==0||j==0||i==m-1||j==n-1)){
                    dfs(i,j,grid,m,n);
                }
            }
        }
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};