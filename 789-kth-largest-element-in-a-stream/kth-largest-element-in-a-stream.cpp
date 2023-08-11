class treeNode {
       public:
      int val;
      treeNode *left;
      treeNode *right;
      treeNode() : val(0), left(nullptr), right(nullptr) {}
      treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
 };

int KthLargest2(treeNode* root, int&k) {
        if( root == NULL) return -1;

        int left_ans = KthLargest2(root->right,k);
        if(left_ans != -1) return left_ans;
        k--;
        if(k == 0) return root->val;
        return  KthLargest2(root->left,k);
    }
  treeNode* insertIntoBST(treeNode* root, int val) {
        if(root == NULL){
            treeNode*newnode = new treeNode(val);
            return newnode;
        }
        if(val < root->val) root->left = insertIntoBST(root->left,val);
        else root->right = insertIntoBST(root->right , val); 
        return root;
    }

class KthLargest {
public:
    int k ;
    priority_queue<int>pq;
    treeNode*root = NULL;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums)
            root = insertIntoBST(root,i);
    }
   
    int add(int val) {
        treeNode*temp = root;
        root  = insertIntoBST(temp,val);
        int s = k;
        return KthLargest2(root,s);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */