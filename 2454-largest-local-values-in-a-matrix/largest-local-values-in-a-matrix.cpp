class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // 1<=i<=n-2
        // 1<=j<=n-2
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2,0));
        vector<int> row = {1,0,-1,0,1,-1,1,-1};
        vector<int> col = {0,1,0,-1,1,-1,-1,1};
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                int maxi = grid[i][j];
                // cout<<grid[i][j]<<"   ";
                for(int k=0;k<8;k++){
                    int nrow = i+row[k];
                    int ncol = j+col[k];
                    // cout<<grid[nrow][ncol]<<" ";
                    maxi = max(maxi,grid[nrow][ncol]);
                }
                ans[i-1][j-1] = maxi;
                // cout<<" maxi "<<maxi<<endl;
            }
        }
        return ans;
    }
};