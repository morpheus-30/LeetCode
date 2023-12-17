/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL||head->next==NULL){
            return head;
        }
        ListNode* temp = head->next;
        ListNode* temp2 = head->next->next;
        head->next=NULL;
        while(temp2!=NULL){
            temp->next = head;
            head = temp;
            temp = temp2;
            temp2 = temp2->next;
        }
        temp->next = head;
        return temp;
        
    }
};