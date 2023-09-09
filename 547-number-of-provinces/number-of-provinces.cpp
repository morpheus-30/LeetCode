class Solution {
public:
    void dfs(vector<int> adj[],int s,vector<int> &visited){
        visited[s] = 1;
        for(auto x:adj[s]){
            if(!visited[x]){
                dfs(adj,x,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> adj[isConnected.size()];
        vector<int> visited(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                count++;
                dfs(adj,i,visited);
            }
        }
        return count;
        
    }
};