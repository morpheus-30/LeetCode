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

    int find(vector<int> v,int key){
        for(int i=0;i<v.size();i++){
            if(v[i]==key){
                return i;
            }
        }
        return -1;
    }

    TreeNode* makeBinaryTreeFromPreIn(vector<int> in,vector<int> pr,int &preOrderIn,int inS,int inE){

        if(inS>inE){
            return NULL;
        }

        TreeNode* node = new TreeNode(pr[preOrderIn]);
        cout<<pr[preOrderIn]<<endl;
        int position = find(in,pr[preOrderIn++]);
        node->left = makeBinaryTreeFromPreIn(in,pr,preOrderIn,inS,position-1);
        node->right = makeBinaryTreeFromPreIn(in,pr,preOrderIn,position+1,inE);
        return node;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int preorderI = 0;
        TreeNode* node;
        node = makeBinaryTreeFromPreIn(inorder,preorder,preorderI,0,inorder.size()-1);
        return node;


    }
};