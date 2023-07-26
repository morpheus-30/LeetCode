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

    void solve(TreeNode* node, int height,int &maxH){
        if(!node){
            maxH = max(height,maxH);
            return;
        }
        solve(node->left,height+1,maxH);
        solve(node->right,height+1,maxH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //maxLeft+maxRight
        if(!root){
            return 0;
        }
        int maxHL = 0;
        int maxHR = 0;
        solve(root->left,0,maxHL);
        solve(root->right,0,maxHR);
        vector<int> v;
        v.push_back(diameterOfBinaryTree(root->left));
        v.push_back(diameterOfBinaryTree(root->right));
        v.push_back(maxHL+maxHR);

        return max(v[0],max(v[1],v[2]));
    }
};