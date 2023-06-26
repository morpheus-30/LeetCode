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
    ListNode *ReverseLL(ListNode *head)
{
    
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *forward = curr->next;
    while (forward != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = forward;
        forward = forward->next;
        if(forward==NULL){
            curr->next=prev;
        }
    }
    return curr;
}
bool isPalindrome(ListNode *head)
{
    if(head->next==NULL){
        return true;
    }
    int size = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    int mid = size % 2 == 0 ? ((size) / 2) : (size / 2) + 1;
    temp = head;
    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    temp = ReverseLL(temp);
    // cout << temp->val << endl;
    for (int i = 0; i < size / 2; i++)
    {
        // cout << head->val << " " << temp->val << endl;
        // cout << "i: " << i << endl;
        // cout<<head->next->val<<endl;
        // cout<<temp->next->val<<endl;
        if (head->val != temp->val)
        {
            return false;
        }
        head = head->next;
        temp = temp->next;
        
    }
    return true;
}
};