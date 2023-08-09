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
class BSTIterator {

    private:
    vector<TreeNode*> inorder;
    TreeNode* curr =NULL;
    int currindex = -1;
    public:
    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    void traversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        traversal(root->left);
        inorder.push_back(root);
        // cout<<root->val<<endl;
        traversal(root->right);
    }
    
    int next() {
        // cout<<currindex<<endl;
        if(currindex==-1){
                currindex++;
                curr=inorder[currindex];
                return curr->val;
        }
        if(currindex+1<inorder.size()){
            currindex++;
            // cout<<curr->val;
            curr = inorder[currindex];
            return curr->val;
        }
        else{
            return -1;
        }
    }
    
    bool hasNext() {
        if(inorder.size()==0){
            return false;
        }
        return currindex==-1||currindex<inorder.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */