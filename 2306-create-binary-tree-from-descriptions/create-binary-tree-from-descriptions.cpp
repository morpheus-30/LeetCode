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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> st;
        unordered_map<int,TreeNode*> mp;
        for(auto x:descriptions){
            int p = x[0];
            int c = x[1];
            int isL = x[2];

            st.insert(c);
            TreeNode* parent = NULL;
            TreeNode* child = NULL;
            if(mp.find(p)==mp.end()){
                parent = new TreeNode(p);
                mp[p] = parent;
            }else{
                parent = mp[p];
            }
            if(mp.find(c)==mp.end()){
                child = new TreeNode(c);
                mp[c] = child;
            }else{
                child = mp[c];
            }

            if(isL){
                parent->left = child;
            }else{
                parent->right = child;
            }
        }
        for(auto x:mp){
            int node = x.first;
            if(st.find(x.first)==st.end()){
                return x.second;
            }
        }
        return NULL;
    }
};