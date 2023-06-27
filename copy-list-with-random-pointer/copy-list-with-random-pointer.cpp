/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head){
        unordered_map<Node*,Node*> mp;
        Node* temp=head;
        Node* dummy = new Node(0);
        Node* last = dummy;
        while(temp!=NULL){
            Node* temp3 = new Node(temp->val);
            last->next = temp3;
            last = temp3;
            mp[temp] = temp3;
            temp = temp->next;
        }
        temp = head;
        last = dummy->next;
        while(temp!=NULL){
            last->random = mp[temp->random];
            temp = temp->next;
            last = last->next;
        }
        return dummy->next;
        
    }
    
};