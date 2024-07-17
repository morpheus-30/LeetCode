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

    void helper(TreeNode* &root,unordered_map<int,int> &mp,vector<TreeNode*> &ans){
        if(root==NULL){
            return;
        }
        
        if(mp.find(root->val)!=mp.end()){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if(right){
                ans.push_back(right);
            }
            if(left){
                ans.push_back(left);
            }
            root = NULL;
            helper(left,mp,ans);
            helper(right,mp,ans);
        }else{
            helper(root->left,mp,ans);
            helper(root->right,mp,ans);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL){
            return {};
        }
        vector<TreeNode*> ans;
        unordered_map<int,int> mp;
        for(auto x:to_delete){
            mp[x] = 1;
        }
        helper(root,mp,ans);
        if(root&&mp.find(root->val)==mp.end()){
            ans.push_back(root);
        }
        vector<TreeNode*> ansans;
        for(auto x:ans){
            if(x==NULL||mp.find(x->val)!=mp.end()){
                continue;
            }
            ansans.push_back(x);
        }
        return ansans;      
    }
};