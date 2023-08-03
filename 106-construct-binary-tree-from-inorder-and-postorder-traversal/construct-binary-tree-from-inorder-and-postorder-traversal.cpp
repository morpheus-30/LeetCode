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


    int find(vector<int> v,int val){
        for(int i=0;i<v.size();i++){
            if(v[i]==val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int> in,vector<int> po,int &ind,int inS,int inE){
        if(ind<0||inE<inS){
            return NULL;
        }

        int element = po[ind--];
        TreeNode* root = new TreeNode(element);
        int position = find(in,element);
        root->right = solve(in,po,ind,position+1,inE);
        root->left = solve(in,po,ind,inS,position-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postorderInd = postorder.size()-1;

        TreeNode* root = solve(inorder,postorder,postorderInd,0,inorder.size()-1);
        return root;
    }
};