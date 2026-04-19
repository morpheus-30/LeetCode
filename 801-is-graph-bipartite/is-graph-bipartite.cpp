class Solution {
public:

    bool solve(vector<vector<int>> &adj,int curr,vector<int> &color){
        for(auto x:adj[curr]){
            if(color[x]==-1){
                color[x] = 1 - color[curr];
                if(!solve(adj,x,color)){
                    return false;
                }
            }else if(color[x] == color[curr]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i] = 0;
                if(!solve(graph,i,color)){
                    return false;
                }
            }
        }
        return true;
    }
};