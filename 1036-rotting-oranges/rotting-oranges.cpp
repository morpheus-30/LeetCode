class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited = grid;
        int countFreshOrange = 0;
        for(int i=0;i<m;i++){
            for(int j =0 ;j<n;j++){
                if(visited[i][j]==2){
                    q.push({i,j});
                }
                if(visited[i][j]==1){
                    countFreshOrange++;
                }
            }        
        }
        if(countFreshOrange==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int minutes = -1;
        vector<int> delr = {-1,0,1,0};
        vector<int> delc = {0,1,0,-1};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newr = row+delr[i];
                    int newc = col+delc[i];
                    if(newr>=0&&newr<m&&newc>=0&&newc<n&&visited[newr][newc]==1){
                        visited[newr][newc] = 2;
                        countFreshOrange--;
                        q.push({newr,newc});
                    }
                }
            }
            minutes++;
        }
        if(countFreshOrange){
            return -1;
        }
        return minutes;


    }
};