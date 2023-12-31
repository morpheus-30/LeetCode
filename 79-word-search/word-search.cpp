#include<bits/stdc++.h>

class Solution {
public:

    vector<int> row = {0,1,0,-1};
    vector<int> col = {-1,0,1,0};

    bool solve(vector<vector<char>> &board,int rowT,int colT,int m,int n,string word,int index,vector<vector<int>> &vis){
        if(index==word.size()){
            return true;
        }
        if (rowT < 0 || colT < 0 || rowT == m || colT == n || board[rowT][colT] == '!')
            return false;
        for(int i=0;i<4;i++){
            int rowI = rowT+row[i];
            int colI = colT+col[i];
            if(rowI>=0&&colI>=0&&rowI<m&&colI<n&&board[rowI][colI]==word[index]&&vis[rowI][colI]==0){
                vis[rowI][colI]=1;
                if(solve(board,rowI,colI,m,n,word,index+1,vis)){
                    return true;
                }
                vis[rowI][colI] = 0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(word.size()>m*n){
            return false;
        }
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if(solve(board,i,j,m,n,word,1,visited)){
                        return true;
                    }
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};