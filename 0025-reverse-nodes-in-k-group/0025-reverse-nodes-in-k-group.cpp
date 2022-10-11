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
    int len(ListNode *head)
    {
        ListNode *temp=head;
        int len=0;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(len(head) < k)
            return head;
        ListNode *prev=NULL,*curr=head,*n=NULL;
        int count=0;
        while(curr!=NULL and count<k)
        {
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
            count++;
        }
        head->next=reverseKGroup(curr,k);        
        return prev;
    }
};