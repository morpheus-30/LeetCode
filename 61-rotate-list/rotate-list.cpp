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
        ListNode* temp = head;
        ListNode* LastOfLL = NULL;
        while(temp->next){
            size++;
            temp = temp->next;
        } 
        k = k%size;
        if(k==0){
            return head;
        }
        LastOfLL = temp;
        temp = head;
        for(int i=0;i<size-k-1;i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        LastOfLL->next = head;
        return newHead;

    }
};