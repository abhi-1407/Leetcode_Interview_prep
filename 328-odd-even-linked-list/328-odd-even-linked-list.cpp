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
//     ListNode *ptr=head;
//         int len=0;
//         while(ptr)
//         {
//             len++;
//             ptr=ptr->next;
//         }
//         int *arr1=new int[len]; 
//         int *arr2=new int[len];
//         ptr=head;
//         int i=0;
//         while(ptr)
//         {
//             arr1[i++]=ptr->val;
//             ptr=ptr->next;
//         }
//         int j=0;
//         for(int i=0;i<len && j<len;i=i+2)
//         {
//             arr2[j++]=arr1[i];
//         }
//         for(int k=1;k<len;k=k+2)
//         {
//             arr2[j++]=arr1[k];
//         }
//         int m=0;
//         ptr=head;
//         while(ptr)
//         {
//             ptr->val=arr2[m++];
//             ptr=ptr->next;
//         }
        
    
       
//     return head;
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *odd=head,*even=head->next,*EvenStart=head->next;
        while(odd->next  && even->next)
        {
          odd->next=even->next;
          odd=odd->next;
          even->next=odd->next;
          even=even->next;
        }
        odd->next=EvenStart;
        if(even && even->next)//in case of even length of ll even's next might not be NULL and even is written to prevent access of NULL's next
            even->next=NULL;
        return head;
        
        
}
};