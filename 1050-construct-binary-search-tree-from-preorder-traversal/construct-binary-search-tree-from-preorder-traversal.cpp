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

    TreeNode* build(vector<int> pre,int &i,int up){
        if(i>=pre.size()||pre[i]>up) return NULL;
        TreeNode* node = new TreeNode(pre[i++]);
        node->left = build(pre,i,node->val);
        node->right = build(pre,i,up);
        return node;
    }

   
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return build(preorder,ind,INT_MAX);
    }
};