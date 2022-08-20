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
private:
    ListNode *Rotate(ListNode *head)
    {
        ListNode *head2=head;
        ListNode *temp=head;
        ListNode *prev=head;
        while(temp->next)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        temp->next=head2;
        return temp;
        
    }
    int length(ListNode *head)
    {
        int len=1;
        while(head->next)
        {
            ++len;
            head=head->next;
        }
        return len;
    }
public:
//     ListNode* rotateRight(ListNode* head, int k) {
//     ListNode *ptr=head;
//     int len=0;
//     if(head==NULL)
//         return NULL;
    
//     while(ptr)
//     {
//         len++;
//         ptr=ptr->next;
//     }
//     k=k%len;
//     int *arr=new int[len];
//     int i=0;
//     ptr=head;
//     while(ptr)
//     {
//        arr[i++]=ptr->val;
//        ptr=ptr->next;
  
//     }
//     for(int i=0;i<k;i++)
//     {    
//     int l=arr[len-1];
//     for(int j=len-1;j>0;j--)
//     {
//         arr[j]=arr[j-1];
//     }
//     arr[0]=l;
//     }
//     ptr=head;
//     i=0;
//     while(ptr)
//     {
//         ptr->val=arr[i++];
//         ptr=ptr->next;
//     }
//     return head;
//     }
     ListNode* rotateRight(ListNode* head, int k){
         if(k==0)
             return head;
        if(head==NULL || head->next==NULL)
            return head;
         ListNode *head1=head;
        int len=length(head1);
        k=k%len;
        // for(int i=0;i<k;i++)
        // {
        //     head=Rotate(head);
        // }
         ListNode *prev,*n=head;
         while(n->next)
         {
             n=n->next;
         }
         n->next=head;         
        
         for(int i=0;i<=len-k;i++)
         {
             prev=n;
             n=n->next;
         }
         prev->next=NULL;
         return n;
     }
    
        
        
       
     
};