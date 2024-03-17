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

    int maxSum(TreeNode* root,int& ans){
        if(root==NULL){
            return 0;
        }
        int leftS = max(maxSum(root->left,ans),0);
        int rightS = max(maxSum(root->right,ans),0);
        ans = max(ans,leftS+rightS+root->val);
        return root->val+max(leftS,rightS);
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans =INT_MIN;
        maxSum(root,ans);
        return ans;
    }
};