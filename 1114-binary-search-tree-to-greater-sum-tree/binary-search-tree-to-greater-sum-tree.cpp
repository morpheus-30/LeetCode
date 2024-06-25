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

	void solve(TreeNode* root,int &sumTNow){

		if(root==NULL){
			return ;		}

		if(root->right==NULL&&root->left==NULL){
			sumTNow+=root->val;
			root->val = sumTNow;
			return ;
		}

		solve(root->right,sumTNow);
		sumTNow+=root->val;
		root->val = sumTNow;
		solve(root->left,sumTNow);
	}

    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL){
        	return NULL;
        }
        int val = 0;
        solve(root,val);
        return root;
    }
};