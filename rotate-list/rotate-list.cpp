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
        
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        k=k%size;
        if(k==0){
            return head;
        }
        temp = head;
        ListNode* prev = NULL;
        for(int i=0;i<size-k;i++){
            prev = temp;
            temp = temp->next;
        }
        ListNode* temp2 = temp;
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }
        prev->next=NULL;
        temp2->next=head;
        return temp;
    }

};