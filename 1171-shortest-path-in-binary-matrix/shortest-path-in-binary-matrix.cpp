class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int n = grid.size();
        if(grid[n-1][n-1] != 0){
            return -1;}
        // vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        grid[0][0]=-1;
        // dist[0][0] = 0;
         int drow[] = {-1, 0, +1, 0, 1, -1, -1, 1};
        int dcol[] = {0, 1, 0, -1, 1, 1, -1, -1}; 

        while(!q.empty()){

            auto top = q.front();
            int row = top.first.first;
            int col = top.first.second;
            int dis = top.second;
            q.pop();
            if(row == n-1&&col == n-1){
                return dis;
            }
            for(int i=0;i<8;i++){
                
                    int newR = row+drow[i];
                    int newC = col+dcol[i];
                    if(newR>=0&&newR<n&&newC>=0&&newC<n&&grid[newR][newC]==0){
                  
                        grid[newR][newC] = -1;
                        q.push({{newR,newC},dis+1});
                    }
                
            }
        }
        return -1;

    }
};