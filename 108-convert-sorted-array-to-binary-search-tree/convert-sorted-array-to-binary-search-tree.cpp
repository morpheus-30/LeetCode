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


    TreeNode* solve(vector<int> nums,int st,int en){
        if(st<0||st>=nums.size()||en<0||en>=nums.size()||st>en){
            return NULL;
        } 
        int medianI = (en+st)/2;
        cout<<nums[medianI]<<endl;
        TreeNode* ret = new TreeNode(nums[medianI]);
        ret->left = solve(nums,st,medianI-1);
        ret->right = solve(nums,medianI+1,en);
        return ret;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        if(nums.size()==1){
            TreeNode* ans = new TreeNode(nums[0]);
            return ans;
        }
        return solve(nums,0,nums.size()-1);
    }
};