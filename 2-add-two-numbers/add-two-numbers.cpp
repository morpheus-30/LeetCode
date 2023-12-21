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
        ListNode* ans = new ListNode(-1);
        ListNode* ansHead = ans;
        int carry = 0;
        while(l1&&l2){
            int somethin = l1->val+l2->val+carry;
            if(somethin<10){
                carry=0;
                ans->next = new ListNode(somethin);
                ans = ans->next;
            }else{
                carry=1;
                ans->next = new ListNode(somethin%10);
                ans = ans->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            while(l1){
                int somethin = l1->val+carry;
                if(somethin<10){
                    carry=0;
                    ans->next = new ListNode(somethin);
                    ans = ans->next;
                }else{
                    carry=1;
                    ans->next = new ListNode(somethin%10);
                    ans = ans->next;
                }
                l1 = l1->next;
            }
        }else if(l2){
            while(l2){
                int somethin = l2->val+carry;
                if(somethin<10){
                    carry=0;
                    ans->next = new ListNode(somethin);
                    ans = ans->next;
                }else{
                    carry=1;
                    ans->next = new ListNode(somethin%10);
                    ans = ans->next;
                }
                l2 = l2->next;
            }
        }
        if(carry==1){
            ans->next = new ListNode(1);
        }
        return ansHead->next;
    }
};