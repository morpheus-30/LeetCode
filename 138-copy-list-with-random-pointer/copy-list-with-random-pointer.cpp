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
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            Node* ans = new Node(head->val);
            if(head->random){
                ans->random = ans;
            }
            return ans;
        }
        unordered_map<Node*,Node*> mp;
        Node* newHead = new Node(head->val);
        Node* tail = newHead;
        Node* temp = head->next;
        mp[head] = newHead;
        while(temp){
            tail->next = new Node(temp->val);
            tail = tail->next;
            mp[temp] = tail;
            temp = temp->next;
        }
        temp = head;
        tail = newHead;
        while(temp&&tail){
                tail->random = mp[temp->random];
            
            temp = temp->next;
            tail = tail->next;
        }
        return newHead;
    }
};