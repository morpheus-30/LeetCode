/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& pre) {
        if (!root) {
            return;
        }
        pre.push_back(root);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }

    static bool cmp(TreeNode* a, TreeNode* b) { return a->val < b->val; }
    int find(vector<TreeNode*> vec,int toFind,int ins,int ine){
        for(int i=ins;i<=ine;i++){
            if(vec[i]->val==toFind){
                return i;
            }
        }
        return -1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> preorderV;
        preorder(root, preorderV);
        vector<TreeNode*> inorder = preorderV;
        sort(inorder.begin(), inorder.end(), cmp);
        int preIndex = 0;
        int inS = 0;
        int inE = inorder.size() - 1;
        pair<int,int> pq;
        pq.first = find(inorder,p->val,inS,inE);
        pq.second = find(inorder,q->val,inS,inE);
        while(inS<=inE){
            int index = find(inorder,preorderV[preIndex]->val,inS,inE);
            cout<<pq.first<<index<<pq.second<<endl;
            if(pq.first==index){
                return p;
            }else if(pq.second==index){
                return q;
            }

            if((pq.first<index&&pq.second>index)||(pq.second<index&&pq.first>index)){
                return preorderV[preIndex];
            }else if((pq.first<index&&pq.second<index)){
                preIndex++;
                inE = index-1;
            }else{
                preIndex+=index-inS+1;
                inS = index+1;
            }
        }
        return NULL;
    }
};