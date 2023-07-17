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
    ListNode *reverse(ListNode *l1)
    {
        ListNode *prev=NULL,*curr=l1,*next=l1;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1=reverse(l1);
        ListNode *r2=reverse(l2);
        ListNode *head=new ListNode(0);
        ListNode *temp=head;
        int carry=0;
        while(r1 && r2)
        {
            int sum=r1->val+r2->val+carry;
            carry=sum/10;
            sum=sum%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
            r1=r1->next;
            r2=r2->next;
        }
        while(r1)
        {
            int sum=r1->val+carry;
            carry=sum/10;
            sum=sum%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
            r1=r1->next;
        }
        while(r2)
        {
            int sum=r2->val+carry;
            carry=sum/10;
            sum=sum%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
            r2=r2->next;
        }
        if(carry>0)
        {
            temp->next=new ListNode(carry);
            temp=temp->next;
        }
        temp->next=NULL;
        ListNode *ans=reverse(head->next);
        return ans;
    }
};