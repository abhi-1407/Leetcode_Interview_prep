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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        ListNode *val1=head,*val2=head;
        int back=count-k+1;
        while(--k)
        {
            val1=val1->next;
        }
        while(--back)
        {
            val2=val2->next;
        }
        swap(val1->val, val2->val);
        return head;
        
        
        
    }
};