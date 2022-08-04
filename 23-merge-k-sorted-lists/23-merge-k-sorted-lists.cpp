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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        int len=lists.size();
        if(len==0)
            return NULL;
        for(int i=0;i<len;i++)
        {
            if(lists[i])//push the lists only if they are non empty
            pq.push(lists[i]);
        }
        
        ListNode *head=NULL,*tail=NULL;
        while(!pq.empty())
        {
            ListNode *temp=pq.top();
            pq.pop();
            
            if(temp->next!=NULL)
            pq.push(temp->next);
            
            if(head==NULL)
            {
                head=temp;
                tail=temp;
            }
            else
            {
                tail->next=temp;//connecting the new node
                tail=temp;//moving tail to the new node to form a linked list
            }
        }
        return head;
    }   

};