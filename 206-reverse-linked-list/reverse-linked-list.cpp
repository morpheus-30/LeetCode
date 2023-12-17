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

    ListNode* solve(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* headNext = head->next;
        ListNode* headNextNext = headNext->next;

        head->next = NULL;
        headNext->next = head;
        if(headNextNext==NULL){
            return head;
        }
        solve(headNextNext)->next = headNext;
        return head;

    }

    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        if(temp==NULL){
            return head;
        }
        while(temp->next!=NULL) temp = temp->next;
        solve(head);
        return temp;
    }
};