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
    void ans(TreeNode *root,int rootmax,int rootmin,int &fans)
    {
        if(!root)
            return;
        rootmax=max(rootmax,root->val);
        rootmin=min(rootmin,root->val);
        fans=max({fans,rootmax-root->val,root->val-rootmin});
        ans(root->left,rootmax,rootmin,fans);
        ans(root->right,rootmax,rootmin,fans);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int fans=0;
        ans(root,INT_MIN,INT_MAX,fans);
        return fans;
    }
};