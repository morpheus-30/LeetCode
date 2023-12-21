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
       ListNode* tempA = headA;
       ListNode* tempB = headB;

       while(tempA&&tempB){
           tempA = tempA->next;
           tempB = tempB->next;
       } 
       int count = 0;
       char flag = ' ';
       if(tempA){
           while(tempA){
               count++;
               tempA = tempA->next;
               flag = 'a';
           }
       }else if(tempB){
           while(tempB){
               count++;
               tempB = tempB->next;
               flag = 'b';
           }
       }
       tempA = headA;
       tempB = headB;
       for(int i=0;i<count;i++){
           if(flag=='a'){
               tempA = tempA->next;
           }else if(flag=='b'){
               tempB = tempB->next;
           }
           
       }
       while(tempA&&tempB){
           if(tempA==tempB){
               return tempA;
           }
           tempA = tempA->next;
           tempB = tempB->next;
       }
       return NULL;
    }
};