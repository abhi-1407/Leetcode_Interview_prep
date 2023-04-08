/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> mpp;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        if(mpp.find(node)==mpp.end())
        {
            mpp[node]=new Node(node->val);
            for(auto it:node->neighbors)
            {
                mpp[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        return mpp[node];
    }
};