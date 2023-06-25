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
    ListNode* reverseLL(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = head->next;
        while(next!=nullptr){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        for(int i=0;i<k-1;i++){
            temp = temp->next;
            if(temp2!=NULL){
                temp2 = temp2->next;
            }else{
                return head;
            }
        }
        if(temp!=NULL){
            temp->next = NULL;
        }
        head = reverseLL(head);
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = reverseKGroup(temp2,k);
        return head;
    }
};