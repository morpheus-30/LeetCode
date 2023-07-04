class Solution {
public:


    bool canPlace(int col,int row,vector<string> ds,int n){
        int duprow = row;
        int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (ds[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (ds[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (ds[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

    void solve(vector<vector<string>> &ans, vector<string> ds,int col,int n){
        if(col==n){
            ans.push_back(ds);
            return;
        }
        for(int row = 0;row<n;row++){
            if(canPlace(col,row,ds,n)){
                ds[row][col] = 'Q';
                solve(ans,ds,col+1,n);
                ds[row][col] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n){
        vector<string> ds(n);
        vector<vector<string>> ans;
         string s(n, '.');
        for (int i = 0; i < n; i++) {
            ds[i] = s;
        }
        solve(ans,ds,0,n);
        return ans;
    }
};