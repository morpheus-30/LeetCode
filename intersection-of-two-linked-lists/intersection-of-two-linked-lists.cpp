/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int count1 = 0;
        int count2 = 0;
        while(temp1!=NULL){
            count1++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            count2++;
            temp2 = temp2->next;
        }
        int diff = count1>count2 ? count1-count2:count2-count1;
        if(count1>count2){
            for(int i=0;i<diff;i++){
                headA = headA->next;
            }
        }else{
            for(int i=0;i<diff;i++){
                headB = headB->next;
            }
        }
        while(headA!=headB&&headA!=NULL&&headB!=NULL){
            headA = headA->next;
            headB = headB->next;
        }
        if(headA!=NULL&&headB!=NULL){
            return headA;
        }else{
            return NULL;
        }

        


    }    
};