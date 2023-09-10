class Solution {
public:

    bool dfs(int src,vector<int> adj[],vector<int> &visited,vector<int> &pathVisited,vector<int> &check){
        visited[src] = 1;
        pathVisited[src] = 1;
        check[src] = 0;
        for(auto x:adj[src]){
            if(!visited[x]){
                if(dfs(x,adj,visited,pathVisited,check)){
                    check[src] = 0;
                    return true;
                }
            }else if(pathVisited[x]){
                check[src] = 0;
                return true;
            }
            
        }
        check[src] = 1;
        pathVisited[src] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph.

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
      
           for(int i=0;i<V;i++){
            for(auto it : graph[i]){
                int x = it;
                adj[i].push_back(x);
            }
        }
        vector<int> check(V,0);
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,pathVisited,check);
            }
        }
        for (int i = 0; i < V; i++) {
			if (check[i] == 1) ans.push_back(i);
		}
        return ans;
        
    }
};