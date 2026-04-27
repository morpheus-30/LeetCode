class Solution {
public:
    //u,d,l,r
    vector<int> dirR = {-1,1,0,0};
    vector<int> dirC = {0,0,-1,1};
    
    vector<vector<bool>> streets = {
        {0,0,1,1},{1,1,0,0},{0,1,1,0},{0,1,0,1},{1,0,1,0},{1,0,0,1}
    };

    int getOppDirn(int n){
        if(n==0||n==1){
            return 1-n;
        }else if(n==2){
            return 3;
        }else{
            return 2;
        }
    }

    bool isValid(int i,int j,int m,int n){
        return i>=0&&j>=0&&i<m&&j<n;
    }

    bool dfs(vector<vector<int>> &grid,int i,int j,int m,int n,vector<vector<int>> &vis){
        if(i==m-1&&j==n-1){
            return true;
        }
        vis[i][j] = true;
        //which direction to go?
        int streetind = grid[i][j] - 1;
        for(int k=0;k<4;k++){
            if(streets[streetind][k] == 1){
                int oppDirn = getOppDirn(k);
                int nrow = i + dirR[k];
                int ncol = j + dirC[k];
                if(isValid(nrow,ncol,m,n)&&!vis[nrow][ncol]&&streets[grid[nrow][ncol]-1][oppDirn]){
                    bool ans = dfs(grid,nrow,ncol,m,n,vis);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        return dfs(grid,0,0,m,n,vis);
    }
};