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
    void helper(TreeNode *root,int &k,int &ans)//note k needs to be passed by reference
    {
        if(!root)
            return;
        helper(root->left,k,ans);
        k--;
        if(k==0)
        {
            ans=root->val;
            return;
        }
        helper(root->right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        helper(root,k,ans);
        return ans;
    }
};