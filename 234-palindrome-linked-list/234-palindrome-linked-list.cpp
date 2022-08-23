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
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr=head,*prev=NULL,*next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;        
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        return true;
        ListNode *slow=head,*fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }            
        ListNode *temp1=head;
        ListNode *temp2=reverse(slow);
        slow->next=NULL;
        while(temp1 and temp2)
        {
            if(temp1->val != temp2->val)
                return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return true;      
        
    }
};