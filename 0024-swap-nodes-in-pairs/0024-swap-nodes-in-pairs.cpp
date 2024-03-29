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
    ListNode *helper(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *curr=head,*next=head->next;
        curr->next=helper(next->next);
        next->next=curr;
        return next;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
    }
};