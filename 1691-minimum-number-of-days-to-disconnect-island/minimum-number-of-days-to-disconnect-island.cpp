class Solution {
public:

    vector<int> rowV = {-1,0,1,0};
    vector<int> colV = {0,1,0,-1};

    bool isValid(int row,int col,vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        return row>=0&&col>=0&&row<m&&col<n;
    }

    void noOfIl(vector<vector<int>> &grid,vector<vector<int>> &vis,int row,int col){
        if(!isValid(row,col,grid)||vis[row][col]||grid[row][col] == 0){
            return;
        }
        vis[row][col] = 1;
        // cout<<row<<" "<<col<<endl;
        for(int i=0;i<4;i++){
            int nrow = row+rowV[i];
            int ncol = col+colV[i];

            noOfIl(grid,vis,nrow,ncol);
        }

    }

    int minDays(vector<vector<int>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<endl;
                if(!vis[i][j]&&grid[i][j]==1){
                    noOfIl(grid,vis,i,j);
                    islands++;  
                }
            }
        }
        if(islands==0||islands>1){
            return 0;
        }    

        

        for(int r =0;r<m;r++){
            for(int c = 0;c<n;c++){
                if(grid[r][c]==1){
                    grid[r][c] = 0;
                    vis.clear();
                    vis.resize(m,vector<int>(n,0));
                    int islands =0;
                    for(int i=0;i<m;i++){
                        for(int j=0;j<n;j++){
                            if(!vis[i][j]&&grid[i][j]==1){
                                noOfIl(grid,vis,i,j);
                                islands++;  
                            }
                        }
                    }
                    // cout<<r<<c<<endl;
                    // cout<<islands<<endl;
                    grid[r][c] = 1;
                    if(islands==0||islands>1){
                        return 1;
                    }    
                }
            }
        }
        return 2;
        

    }
};