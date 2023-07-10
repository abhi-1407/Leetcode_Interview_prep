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
    int helper(TreeNode *root)
    {
        if(!root)
            return 1e5;
        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        return 1+min(helper(root->left),helper(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        int ans=helper(root);
        return ans==1e5?0:ans;
    }
};