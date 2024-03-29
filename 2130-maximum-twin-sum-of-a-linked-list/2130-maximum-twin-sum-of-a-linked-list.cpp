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
    int pairSum(ListNode* head) {
        if(!head->next->next)
            return head->val+head->next->val;
        ListNode *slow=head,*fast=head,*prev=head;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=reverse(slow);
        ListNode *p1=head,*p2=prev->next;
        int maxi=INT_MIN;
        while(p1 && p2)
        {
            int sum=p1->val+p2->val;
            maxi=max(maxi,sum);
            p1=p1->next;
            p2=p2->next;
        }
        return maxi;
    }
};