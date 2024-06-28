class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> assign(n,-1);
        vector<int> visited(n,-1);
        vector<int> adj[n];
        for(auto x:roads){
        	adj[x[0]].push_back(x[1]);
        	adj[x[1]].push_back(x[0]);
        }
        int root = 0;

        // for(int i=1;i<n;i++){
        // 	if(adj[i].size()>adj[root].size()){
        // 		root = i;
        // 	}
        // }
        int nextVal = n;
        priority_queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({adj[i].size(),i});
        }
        // q.push({adj[root].size(),root});
        while(!q.empty()){
        	auto front = q.top();
        	q.pop();


        	int r = front.first;
        	int node = front.second;
            cout<<nextVal<<" "<<node<<endl;
            if(assign[node]==-1){
                assign[node] = nextVal;
                nextVal--;
            }

        	for(auto x:adj[node]){
        		if(visited[x]==-1){
                    visited[x] = 1;
        			q.push({adj[x].size(),x});
        		}
        	}
        }
        
        long long ans = 0;
        for(auto x:roads){
            ans+=(assign[x[0]]+assign[x[1]]);
        }
        return ans;
    }
};