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

    void sovle(TreeNode* root,int height,int &maxH){
        if(!root){
            maxH = max(maxH,height);
            return;
        }
        sovle(root->left,height+1,maxH);
        sovle(root->right,height+1,maxH);
    }

    int maxDepth(TreeNode* root) { 
        int maxH = 0;
        sovle(root,0,maxH);
        return maxH;
    }
};