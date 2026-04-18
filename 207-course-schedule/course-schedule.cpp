class Solution {
public:

    bool solve(unordered_map<int,vector<int>> &adj,vector<int> &visited,vector<int> &rec,int curr){
        if(rec[curr]) return true;     // cycle
        if(visited[curr]) return false; // already processed safely

        rec[curr] = true;
        visited[curr] = true;

        for(auto x:adj[curr]){
            if(visited[x]&&rec[x]){
                return true;
            }else if(!visited[x]){
                int iscy = solve(adj,visited,rec,x);
                if(iscy){
                    return true;
                }
            }
        }
        rec[curr] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;

        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> rec(numCourses,0);
        vector<int> vis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                int ans = solve(adj,vis,rec,i);
                if(ans){
                    return !ans;
                }
            }
        }
        return true;


    }
};