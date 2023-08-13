class treenode {
       public:
      int val;
      treenode *left;
      treenode *right;
      treenode() : val(0), left(nullptr), right(nullptr) {}
      treenode(int x) : val(x), left(nullptr), right(nullptr) {}
      treenode(int x, treenode *left, treenode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    treenode* rootNode = NULL;
    int k ;
public:

    

    treenode* insertIntoBST(int val,treenode* root){
        if(root==NULL){
            treenode* node = new treenode(val);
            return node;
        }
        if(val<root->val){
            root->left = insertIntoBST(val,root->left);
        }else{
            root->right = insertIntoBST(val,root->right);
        }
        return root;
    }

    int kthlargest(treenode* root,int &k){
        if(root==NULL){
            return -1;
        }
        int leftans = kthlargest(root->right,k);
        if(leftans!=-1){
            return leftans;
        }
        k--;
        if(k==0){
            return root->val;
        }
        return kthlargest(root->left,k);
    }

    int findKthLargest(vector<int>& nums, int k) {

        this->k = k;
        for(auto x:nums){
            rootNode = insertIntoBST(x,rootNode);
        }
        return kthlargest(rootNode,k);
    }

};