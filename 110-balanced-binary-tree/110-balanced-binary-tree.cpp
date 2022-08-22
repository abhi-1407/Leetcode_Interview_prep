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
    pair<bool,int> helper(TreeNode *root)
    {
        if(!root)
            return {true,0};
        auto lh=helper(root->left);
        auto rh=helper(root->right);
        int maxh=max(lh.second,rh.second)+1;
        if(abs(lh.second-rh.second)<=1 and lh.first and rh.first)
        {
            return {true,maxh};
        }
        return {false,maxh};
    }
public:
    bool isBalanced(TreeNode* root) {
        auto it=helper(root);
        return it.first;
    }
};