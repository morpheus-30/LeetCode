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
        if(!head||!head->next){
            return head;
        }
        int size = 1;
        ListNode* LastOfLL = head;
        while(LastOfLL->next){
            size++;
            LastOfLL = LastOfLL->next;
        } 
        k = k%size;
        if(k==0){
            return head;
        }
        LastOfLL->next = head;
        ListNode* newHead = NULL;
        for(int i=0;i<size-k-1;i++){
            head = head->next;
        }
        newHead = head->next;
        head->next = NULL;
        return newHead;

    }
};