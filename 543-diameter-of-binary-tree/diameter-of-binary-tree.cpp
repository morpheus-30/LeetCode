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
    int heightOfTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int lefth = heightOfTree(root->left);
        int righth = heightOfTree(root->right);
        return 1+max(lefth,righth);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        //3
        //1 --> left subtree
        //2 --> right subtree
        //3 --> left+right = height of left+right
        int right = diameterOfBinaryTree(root->left);
        int left = diameterOfBinaryTree(root->right);
        int left_right =heightOfTree(root->left)+heightOfTree(root->right);
        return max(left,max(right,left_right));
    }
};