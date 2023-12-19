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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* fast = head;
        ListNode* slow = start;

        while(fast&&fast->next){
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            slow = slow->next;
        }
        if(slow->next){
            slow->next = slow->next->next;
        }
        return start->next;
    }
};