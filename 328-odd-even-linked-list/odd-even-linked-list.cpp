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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* ans = new ListNode(-1);
        ListNode* anshead = ans;
        while(odd){
            ans->next = new ListNode(odd->val);
            ans = ans->next;
            odd = odd->next;
            if(odd){
                odd = odd->next;
            }
        }
        while(even){
            ans->next = new ListNode(even->val);
            ans = ans->next;
            even = even->next;
            if(even){
                even = even->next;
            }
        }
        return anshead->next;
        
    }
};