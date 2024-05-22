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
    int totalmoves = 0;

    vector<int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        

        auto lvec=solve(root->left);
        auto rvec=solve(root->right);
        int lsize = lvec[0];
        int lextra = lvec[1];

        int rsize = rvec[0];
        int rextra = rvec[1];

        int extrahere = (lextra)+(rextra)+root->val;
        int totalsize = rsize+lsize+1;
        totalmoves+=abs(extrahere-totalsize);
        return {totalsize,extrahere};

    }

    int distributeCoins(TreeNode* root) {
        solve(root);
        return totalmoves;
    }
};