/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:


    Node* dfs(Node* node,unordered_map<Node*,Node*> &mp){
        vector<Node*> neighbours;
        Node* ret = new Node(node->val);
        mp[node] = ret;
        for(auto x:node->neighbors){
            if(mp.find(x)!=mp.end()){
                neighbours.push_back(mp[x]);
            }else{
                neighbours.push_back(dfs(x,mp));
            }
        }
        ret->neighbors = neighbours;
        return ret;
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        if(node->neighbors.size()==0){
            Node* ret = new Node(node->val);
            return ret;
        }
        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);

    }
};