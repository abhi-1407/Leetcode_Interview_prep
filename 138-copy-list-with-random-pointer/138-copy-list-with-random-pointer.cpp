/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

public:
    Node* copyRandomList(Node* head) {
        Node *h=NULL,*temp=head;
        unordered_map<Node*,Node*> mpp;
        while(temp)
        {
            mpp[temp]=new Node(temp->val);//to map every node with the new node
            temp=temp->next;
        }
        temp=head;//pointing to the head of the original linked list       
       /* connects next of the new ll with its corresponding next element  and same goes for random as well*/
        while(temp)
        {
            mpp[temp]->next=mpp[temp->next];
            mpp[temp]->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
       }
};