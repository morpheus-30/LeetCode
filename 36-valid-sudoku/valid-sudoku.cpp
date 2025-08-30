class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> rows(9);
        vector<unordered_map<int,int>> cols(9);
        vector<vector<unordered_map<int,int>>> squares(3,vector<unordered_map<int,int>>(3));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }else{
                    if(rows[i][board[i][j]] || cols[j][board[i][j]] || squares[i/3][j/3][board[i][j]] ){
                        return false;
                    }
                    rows[i][board[i][j]] = 1;
                    cols[j][board[i][j]] = 1;
                    squares[i/3][j/3][board[i][j]] = 1;
                }
            }
        }
        return true;
    }
};