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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;
        while(head!=NULL){
            if(mp[head]){
                return true;
            }
            mp[head] = 1;
            head = head->next;
        }
        return false;
    }
};