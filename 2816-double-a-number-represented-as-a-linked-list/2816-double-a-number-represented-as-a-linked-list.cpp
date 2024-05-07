class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        
        ListNode* temp = head;
        while (temp != nullptr) {
            temp->val = (temp->val * 2) % 10;
            if (temp->next != nullptr && temp->next->val > 4) {
                temp->val++;
            }
            temp = temp->next; 
        }
        return head;
    }
};