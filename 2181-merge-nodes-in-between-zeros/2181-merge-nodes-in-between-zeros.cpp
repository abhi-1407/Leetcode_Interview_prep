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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp=head;
        ListNode *ans=new ListNode(0);
        ListNode *ansTemp=ans;
        int tempSum=0;
        bool first=true;
        while(temp!=nullptr)
        {
            if(temp->val==0 || first)
            {
               if(first)
               {
                   first=false;
               }
                else
                {
                    ans->next=new ListNode(tempSum);
                    ans=ans->next;
                    tempSum=0;
                }
            }
            else
            {
                tempSum+=temp->val;
            }
            temp=temp->next;
        }
        return ansTemp->next;
    }
};