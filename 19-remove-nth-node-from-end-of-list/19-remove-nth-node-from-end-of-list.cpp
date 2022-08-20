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
//    ListNode* removeNthFromEndFunc(ListNode* head, int& n, ListNode* &ans) {
//         if(!head){
//             return head;
//         }     
        
//         head->next = removeNthFromEndFunc(head->next, n, ans);
        
//         if(n == 0){
//             ans = head;
//         }
//         n--;
        
//         return head;
//     }   
    
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* ans = NULL;
//         ListNode* root = removeNthFromEndFunc(head, n, ans);    
        
//         if(!ans){
//             return head->next;
//         }
        
//         ans->next = (ans->next)->next;
//         return head;
//     }
     ListNode* removeNthFromEnd(ListNode* head, int n){
         
        ListNode *fast=head,*slow=head;
        for(int i=1;i<=n;++i)
        {
            fast=fast->next;
        }
        if(fast==NULL)
            return slow->next;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            
        }
        slow->next=slow->next->next;
        return head;
     }
};