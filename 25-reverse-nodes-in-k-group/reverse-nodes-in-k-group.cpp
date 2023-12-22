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

    ListNode* reverseLL(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* next = head->next;
        ListNode* curr = head;
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next){
            return head;
        }
        ListNode* tail = head;
        for(int i=0;tail&&i<k-1;i++){
            tail = tail->next;
        }
        if(!tail){
            return head;
        }
        ListNode* temp = tail->next;
        tail->next = NULL;
        tail = head;
        head = reverseLL(head);
        tail->next = reverseKGroup(temp,k);
        return head;
    }
};