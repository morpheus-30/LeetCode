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

    

    int countNodes(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        int lh = 0;
        int rh = 0;
        TreeNode* temp = root;
        while(temp){
            lh++;
            temp = temp->left;
        }
        temp = root;
        while(temp){
            rh++;
            temp = temp->right;
        }
        cout<<lh<<rh<<endl;

        if(lh==rh){
            return pow(2,lh)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);



    }   
};