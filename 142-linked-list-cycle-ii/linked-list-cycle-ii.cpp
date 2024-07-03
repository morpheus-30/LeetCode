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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        slow = head;
        while(slow&&fast&&slow!=fast){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};