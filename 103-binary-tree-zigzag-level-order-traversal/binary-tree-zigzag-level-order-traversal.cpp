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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> dq;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        dq.push(root);
        bool LtoR = true;
        while(!dq.empty()){
            int size = dq.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* frontNode = dq.front();
                dq.pop();
                
                int index = LtoR ? i : size - i -1;
                row[index] = frontNode->val;

                if(frontNode->left){
                    dq.push(frontNode->left);
                }
                if(frontNode->right){
                    dq.push(frontNode->right);
                }
                
            }
            LtoR = !LtoR;
            ans.push_back(row);
        }
        return ans;
    }
};