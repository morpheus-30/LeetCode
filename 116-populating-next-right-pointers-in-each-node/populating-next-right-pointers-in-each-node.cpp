/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //level order traversal

        if(!root){
            return root;
        }
        queue<pair<Node*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            // Node* frontNode = q.front().first;
            // q.pop();
            for(int i=0;i<size;i++){
                Node* frontNode = q.front().first;
                cout<<q.front().first->val<<" "<<q.front().second<<endl;
                int level = q.front().second;
                q.pop();
                if(frontNode->left){
                    q.push({frontNode->left,level+1});
                }
                if(frontNode->right){
                    q.push({frontNode->right,level+1});
                }
               
                frontNode->next = q.front().second==level&&!q.empty()?q.front().first:NULL;
            }
        }
        return root;
    }
};