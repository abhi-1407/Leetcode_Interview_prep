class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p=head;
        ListNode *q=head;
        if(head==NULL)
        return NULL;
        
        if(head->next==NULL)
        return NULL;
        ListNode *start=head;
        while(q!=NULL && q->next!=NULL)
        {
            
            p=p->next;
            q=q->next->next;
            if(p==q)
            {
                while(start!=p)
                {
                    start=start->next;
                    p=p->next;
                }
                return p;
            }
            
        }
        return NULL;
    }
    
        
             
};