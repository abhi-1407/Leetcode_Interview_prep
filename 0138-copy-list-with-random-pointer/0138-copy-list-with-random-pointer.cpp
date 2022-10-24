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
       //  Node *h=NULL,*temp=head;
       //  unordered_map<Node*,Node*> mpp;
       //  while(temp)
       //  {
       //      mpp[temp]=new Node(temp->val);//to map every node with the new node
       //      temp=temp->next;
       //  }
       //  temp=head;//pointing to the head of the original linked list       
       // /* connects next of the new ll with its corresponding next element  and same goes for random as well*/
       //  while(temp)
       //  {
       //      mpp[temp]->next=mpp[temp->next];
       //      mpp[temp]->random=mpp[temp->random];
       //      temp=temp->next;
       //  }
       //  return mpp[head];
       // }
       if(!head)
           return NULL;
        Node *temp=head;
        
        //making new nodes after the old nodes
        while(temp)
        {
            Node *newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        
        //connecting random nodes as well
        temp=head;
        while(temp)
        {
            temp->next->random=temp->random?temp->random->next:NULL;//temp's random pointer's new node is actually after it
            temp=temp->next->next;//move it by 2 steps
        }
        
        Node *clone=head->next,*result=head->next;
        Node *original=head;
        //splitting both the lists
        while(original)
        {
            original->next=original->next->next;
            clone->next=(clone->next)?clone->next->next:NULL;
            original=original->next;
            clone=clone->next;
        }
        return result;
    }
};