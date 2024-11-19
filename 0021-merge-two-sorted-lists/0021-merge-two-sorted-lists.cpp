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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        
        while(h1!=NULL && h2!=NULL){
            if(h1->val <= h2->val){
                temp->next = h1;
                h1=h1->next;
            }
            else{
                temp->next = h2;
                h2=h2->next;
            }
            temp=temp->next;
        }
        
        if(h1!=NULL){
            temp->next=h1;  
        }else{
            temp->next=h2;
        }
        
        return head->next;
    }
};