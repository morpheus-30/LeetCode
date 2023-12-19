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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(9);
        ListNode* temp = start;
        start->next = head;
        for(int i=0;i<n;i++){
            temp = temp->next;
        }
        ListNode* tempS = start;
        while(temp->next!=NULL){
            temp = temp->next;
            tempS = tempS->next;
        }
        // if(temp==NULL){
        //     return head->next;
        // }
        // if(tempS->next){
            tempS->next = tempS->next->next;
        // }else{
            // tempS->next=NULL;
        // }
        return start->next;
    }
};