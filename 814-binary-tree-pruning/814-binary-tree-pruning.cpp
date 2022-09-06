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
    TreeNode *helper(TreeNode *root)
    {
        if(!root)//base case
            return NULL;
        root->left=helper(root->left);//call dfs on the left
        root->right=helper(root->right);//call dfs on the right
        if(!root->left && !root->right && !root->val)
        {
            delete(root);//free the space to avoid memory leak
            return NULL;//delete this node
        }
        return root;//return the root ,as no deletion happened
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};