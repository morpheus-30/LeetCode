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
    int heightOfTree(TreeNode* root,int& diameter){
        if(root==NULL){
            return 0;
        }
        
        int lefth = heightOfTree(root->left,diameter);
        int righth = heightOfTree(root->right,diameter);
        diameter = max(diameter,lefth+righth);
        return 1+max(lefth,righth);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftD;
        int rightD;
        //3
        //1 --> left subtree
        //2 --> right subtree
        //3 --> left+right = height of left+right
        int leftH = heightOfTree(root->left,leftD);
        int rightH = heightOfTree(root->right,rightD);
        int left_right = leftH+rightH;
        return max(leftD,max(rightD,left_right));
    }
};