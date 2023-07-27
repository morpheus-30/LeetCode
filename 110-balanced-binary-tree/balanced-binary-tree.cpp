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

    
    pair<bool,int> solve(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }

        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right);
        bool leftA = left.first;
        bool rightA = right.first;
        bool comb = abs(left.second-right.second)<=1;

        pair<bool,int> ans;
        ans.first = leftA&&rightA&&comb;
        ans.second = max(left.second,right.second)+1;
        
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return solve(root).first;

    }
};