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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int count = 0;
        int n = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            n++;
            temp = temp->next;
        }   
        int mid = n/2;
        temp = head;
        while(count!=mid&&temp!=NULL){
            temp = temp->next;
            count++;
        }
        return temp;
    }
};