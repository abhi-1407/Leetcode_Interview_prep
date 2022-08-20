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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow_ptr=head;
        ListNode *fast_ptr=head;
        while(fast_ptr->next and fast_ptr->next->next)
        {
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
        }
        if(fast_ptr->next!=NULL)
        {
            if(fast_ptr->next->next==NULL)
               return slow_ptr->next;  
        }
           
        return slow_ptr;
        
        
    }
};