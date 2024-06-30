

class DisjointSet{
    public:
	vector<int> parent;
	vector<int> rank;
	int size;

	DisjointSet(int nodes){
		parent.resize(nodes+1);
		rank.resize(nodes+1,1);

		for(int i=0;i<nodes;i++){
			parent[i] = i;
		}
		size = nodes;
	}

	int getUP(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=getUP(parent[node]);
	}

	bool unionWithMe(int u,int v){
		int up = getUP(u);
		int vp = getUP(v);

		if(up==vp){
			return false;
		}

		if(rank[up]>=rank[vp]){
			rank[up] = max(rank[vp]+1,rank[up]);
			parent[vp] = up;
		}else{
			rank[vp] = max(rank[up]+1,rank[vp]);
			parent[up] = vp;
		}
		size--;
		return true;
	}

	bool isConnected(){
        // cout<<size<<endl;
		return size==1;
	}

};



class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);

        int edgesRequired = 0;
        for(auto x:edges){
        	if(x[0]==3){
        		edgesRequired += alice.unionWithMe(x[1],x[2]) | bob.unionWithMe(x[1],x[2]);
        	}
        }

        for(auto x:edges){
        	if(x[0]==1){
        		edgesRequired += alice.unionWithMe(x[1],x[2]) ;
        	}
        	if(x[0]==2){
        		edgesRequired += bob.unionWithMe(x[1],x[2]);
        	}
        }
        cout<<edgesRequired<<endl;

        if(alice.isConnected()&&bob.isConnected()){
        	return edges.size() - edgesRequired;
        }

        return -1;


    }
};