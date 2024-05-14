class Solution {
public:
    vector<int> row = {0,1,0,-1};
    vector<int> col = {1,0,-1,0};
    bool checkValid(int row,int col,int m,int n){
        if(row>=0&&col>=0&&row<m&&col<n){
            return true;
        }
        return false;
    }

    void helper(vector<vector<int>> &visited,int r,int c,vector<vector<int>> &grid,int currsum,int &finalsum){
        currsum+=grid[r][c];
        int m = grid.size();
        int n = grid[0].size();
        visited[r][c] = 1;
        for(int i=0;i<4;i++){
            int nrow = r+row[i];
            int ncol = c+col[i];

            if(checkValid(nrow,ncol,m,n)&&grid[nrow][ncol]!=0&&!visited[nrow][ncol]){
                helper(visited,nrow,ncol,grid,currsum,finalsum);
            }
        }
        finalsum = max(finalsum,currsum);
        visited[r][c] = 0;

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                int currsum = 0;
                int finalans = 0;
                if(grid[i][j]!=0){
                    helper(visited,i,j,grid,currsum,finalans);
                }
                ans = max(ans,finalans);
            }
        }      
        return ans;
    }
};