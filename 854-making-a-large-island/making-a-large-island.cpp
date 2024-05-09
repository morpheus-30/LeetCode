class Solution {
public:
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    int findPar(int node , vector<int> &parent)
    {
        if(parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node] , parent);
    }
    
    void unionn(int u,int v,vector<int> &parent , vector<int> &rank)
    {
        u = findPar(u , parent);
        v= findPar(v , parent);
        if(u==v)
            return;
        if(rank[u] > rank[v])
            parent[v] = u;
        else if(rank[u] < rank[v])
            parent[u] =v;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
    
    void bfs(int &i , int&j ,vector<vector<int>> &vis,int &n ,int &m,vector<vector<int>>& grid,vector<int> &parent ,vector<int> &rank,vector<int> &count)
    {
        
        queue<pair<int,int>> q;
        pair<int,int> p = {i,j};
        vis[i][j] = 1;
        int pi = i*m+j;
        q.push(p);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                p = q.front();
                int r = p.first;
                int c = p.second;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nr = r+dx[j];
                    int nc = c+dy[j];
                    
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || !grid[nr][nc])
                        continue;
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                    int ci = nr*m+nc;
                    unionn(pi , ci ,parent , rank);
                    count[pi]++;
                }
            }
        }
    }
    
    int findMax(vector<vector<int>>& grid,vector<int> &parent ,vector<int> &rank,vector<int> &count,int &n ,int &m)
    {
        
        int ans = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mx = 1;
                if(!grid[i][j])
                {
                    unordered_set<int> ust;
                    for(int k=0;k<4;k++)
                    {
                        
                        int nr = i+dx[k];
                        int nc = j+dy[k];
                    
                        if(nr < 0 || nr >= n || nc < 0 || nc >= m || !grid[nr][nc])
                            continue;
                         int ci = nr*m+nc;
                         int pi = findPar(ci , parent);
                        if(ust.count(pi))
                            continue;
                        mx+= count[pi];
                        ust.insert(pi);
                     }
                    ans = max(ans ,  mx);
                    //cout << i << ":" << j << ":" << mx << "  ";
                }
            }
        }
        int szz = n*m+1;
        for(int i=0;i < szz ;i++)
            ans = max(ans , count[i]);
        return ans;
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = n*m+1 ,ans = 0;
        vector<int> parent(sz) , rank(sz,0) , count(sz,1);
        for(int i=0;i<sz;i++)
            parent[i] = i;
        
        vector<vector<int>> vis(n , vector<int>(m , 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    //count++;
                    bfs(i,j,vis,n,m,grid,parent,rank,count);
                }
            }
        }
        // int k = 1*m+3;
        // cout << findPar(k,parent) << ":"<< count[8] <<"    ";
        return findMax(grid,parent,rank,count,n,m);
    }
};