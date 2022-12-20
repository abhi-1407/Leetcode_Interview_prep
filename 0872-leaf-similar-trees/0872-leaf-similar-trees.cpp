/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void leaf(string &s,TreeNode *root)
    {
        if(!(root->left) && !(root->right))
        {
            s+=to_string(root->val)+"#";
            return;
        }
        else
        {
            if(root->left)
                leaf(s,root->left);
        
            if(root->right)
                leaf(s,root->right);
            
        }
        
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1,s2;
        leaf(s1,root1);
        leaf(s2,root2);        
        return s1==s2;
    }
};