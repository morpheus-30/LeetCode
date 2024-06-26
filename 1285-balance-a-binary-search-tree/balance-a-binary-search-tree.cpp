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


    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderV;
        inorder(root,inorderV);
        return buildBST(inorderV,0,inorderV.size()-1);
    }

    void inorder(TreeNode* root,vector<int> &ino){
    	if(root==NULL){
    		return;
    	}
    	inorder(root->left,ino);
    	ino.push_back(root->val);
    	inorder(root->right,ino);
    }

    TreeNode* buildBST(vector<int> &inorder,int l,int r){
    	if(l>r){
    		return NULL;
    	}
    	int mid = (l+r)/2;
    	TreeNode* root = new TreeNode(inorder[mid]);
    	root->left = buildBST(inorder,l,mid-1);
    	root->right = buildBST(inorder,mid+1,r);
    	return root;
    }
};