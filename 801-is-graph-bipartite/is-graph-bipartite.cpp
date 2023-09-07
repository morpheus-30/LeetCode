class Solution {
public:

    bool bfs(vector<vector<int>> graph,vector<int> color,int i){
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto x:graph[front]){
                if(color[x]==-1){
                    q.push(x);
                    color[x] = !color[front];
                }else if(color[x]==color[front]){
                    return false;
                }
            }

        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!bfs(graph,color,i)){
                    return false;
                }
            }
        }
        return true;
        
    }
};