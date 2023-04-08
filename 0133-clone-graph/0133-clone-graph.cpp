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
    /* we need to make a correspondance from original node to the clone node */
    unordered_map<Node*,Node*> mpp; 
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return {};
        mpp[node]=new Node(node->val,{});
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto i:it->neighbors)
            {
                if(mpp.find(i)==mpp.end())
                {
                    mpp[i]=new Node(i->val,{});
                    q.push(i);
                }
                mpp[it]->neighbors.push_back(mpp[i]);
            }
        }
        return mpp[node];
    }
};