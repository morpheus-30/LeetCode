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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode;
        ListNode* ans = start;
        int carry = 0;
        while(l1!=NULL&&l2!=NULL){
            start->next = new ListNode;
            int sum = l1->val+l2->val+carry;
            start->next->val = sum%10;
            sum = sum/10;
            carry = sum;
            start = start->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL){
            while(l2!=NULL){
                start->next = new ListNode;
                int sum = l2->val+carry;
                start->next->val = sum%10;
                sum = sum/10;
                carry = sum;
                start = start->next;
                l2 = l2->next;
            }
        }else if(l2 == NULL){
            while(l1!=NULL){
                start->next = new ListNode;
                int sum = l1->val+carry;
                start->next->val = sum%10;
                sum = sum/10;
                carry = sum;
                start = start->next;
                l1 = l1->next;
            }
        }
        if(carry!=0){
            start->next = new ListNode;
            start->next->val = carry;
        }
        
        return ans->next;
    }
};