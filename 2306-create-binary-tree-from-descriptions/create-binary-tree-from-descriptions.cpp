/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* root,unordered_map<int,vector<pair<int,int>>> &adj){

        if(adj.find(root->val)==adj.end()){
            return;
        }

        for(auto x:adj[root->val]){
            int c = x.first;
            int isL = x.second;
            TreeNode* temp = new TreeNode(c);
            if(isL){
                root->left = temp;
            }else{
                root->right = temp;
            }
            dfs(temp,adj);
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> notRoot;
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> possibleRoots;
        for(auto x:descriptions){
            int p = x[0];
            int c = x[1];
            int isL = x[2];

            notRoot[c] = -1;
            if(notRoot.find(p)==notRoot.end()){
                possibleRoots.push_back(p);
            }
            adj[p].push_back({c,isL});
        }
        int rootVal = -1;
        for(auto x:possibleRoots){
            if(notRoot[x]!=-1){
                rootVal = x;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootVal);
        dfs(root,adj);
        return root;
    }
};