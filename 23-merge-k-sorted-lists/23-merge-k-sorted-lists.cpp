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
 class compare{
    public:
    bool operator()(ListNode *a,ListNode *b)
    {
        return a->val > b->val;
    }  
    }; 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        priority_queue<ListNode*,vector<ListNode *>,compare> pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            pq.push(lists[i]);
        }
        ListNode *head=NULL,*n=NULL;
        while(!pq.empty())
        {
            ListNode *temp=pq.top();
            pq.pop();
            if(temp->next)
            pq.push(temp->next);
            if(head==NULL)
            {
                 head=temp;
                 n=temp;
            }  
            else
            {
                n->next=temp;
                n=n->next;                
            }
           
        }
        return head;
    }
};