class Solution {
    bool isValid(int r,int c,int m,int n){
        if(r<m&&r>=0&&c<n&&c>=0){
            return true;
        }
        return false;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};


        vector<vector<int>> v(m,vector<int>(n,0));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!v[i][j]&&grid[i][j] == '1'){
                    count++;
                    cout<<count<<endl;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    v[i][j] = 1;
                    while(!q.empty()){
                        pair<int,int> front = q.front();
                        q.pop();
                        int r = front.first;
                        int c = front.second;

                        for(int k=0;k<4;k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if(isValid(nr,nc,m,n)&&!v[nr][nc]){
                                if(grid[nr][nc] == '1'){
                                    q.push({nr,nc});
                                    v[nr][nc] = 1;
                                }
                            }
                        }
                    }

                }
            }
        }
        return count;
    }
};