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


    int height(TreeNode* node,int heigt){
        if(node==NULL){
            return heigt;
        }
        return max(height(node->left,heigt+1),height(node->right,heigt+1));
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool comb = abs(height(root->left,0)-height(root->right,0))<=1;

        if(left&&right&&comb){
            return true;
        }else{
            return false;
        }

    }
};