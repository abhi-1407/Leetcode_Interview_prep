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
    ListNode *middle(ListNode *head)
    {
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        return temp;
    }

    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
            curr = curr ->next;
        }
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
        
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *left=head;
        ListNode *mid=middle(head);
        ListNode *right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};