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
        if(!head)
            return NULL;
        if(!head->next)
            return NULL;
        
        ListNode *fast=head, *slow=head,*prev=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *temp=slow;
        prev->next=slow->next;
        delete(temp);
        return head;          
        
    }
};