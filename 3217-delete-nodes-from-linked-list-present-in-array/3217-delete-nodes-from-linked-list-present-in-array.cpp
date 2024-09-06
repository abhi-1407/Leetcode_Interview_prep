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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> map;

        for(int num : nums){
            map[num]++;
        }

        ListNode* ptr1 = head;

        while(map.find(ptr1->val) != map.end()){
            ptr1 = ptr1->next;
            head = head->next;
        }

        ListNode* ptr2 = ptr1->next;

        while(ptr2){
            if(map.find(ptr2->val) != map.end()){
                ptr2 = ptr2->next;
                ptr1->next = ptr2;
            }
            else{
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
        }


        return head;
    }
    
};