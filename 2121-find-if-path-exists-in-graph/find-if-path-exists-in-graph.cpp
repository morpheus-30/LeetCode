class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> q;
        vector<int> visited(n,0);
        q.push(source);
        // visited[source] = 1;
        vector<int> adj[n];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = 1;
            if(node==destination){
                return true;
            }
            for(auto x:adj[node]){
                if(!visited[x]){
                    q.push(x);
                }
            }
        }
        return false;
        
    }
};