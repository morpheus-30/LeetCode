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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        ListNode* last;
        ListNode* curr;
        last = head;
        curr = head;
        int n = 1;
        while(last->next != NULL){
            last = last->next;
            n++;
        }
        curr = head;
        k = k % n;
        if(k==0){
            return head;
        }
        while(n-k>1){
            curr = curr->next;
            k++;
        }

        last->next = head;
        if(curr != last){
            head = curr->next;
            curr->next = NULL;
        }else{
            head = last;
        }
        
        return head;


    }
};