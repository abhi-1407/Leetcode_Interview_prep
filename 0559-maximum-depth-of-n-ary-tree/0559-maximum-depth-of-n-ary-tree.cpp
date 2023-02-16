/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int helper(Node *root)
    {
        if(root==NULL)
            return 0;
        int maxi=0;
        for(auto it:(root->children))
        {
            maxi=max(maxi,helper(it));
        }
        return maxi+1;
    }
public:
    int maxDepth(Node* root) {
        return helper(root);
    }
};