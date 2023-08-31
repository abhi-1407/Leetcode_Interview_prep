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
    int helper(TreeNode *root,map<TreeNode *,int> &mpp)
    {
        if(!root)
            return 0;
        if(mpp.find(root)!=mpp.end())
            return mpp[root];
        int take=root->val,nottake=0;
        if(root->left)
        {
            take+=helper(root->left->left,mpp)+helper(root->left->right,mpp);
        }
        if(root->right)
        {
            take+=helper(root->right->left,mpp)+helper(root->right->right,mpp);
        }
        nottake=helper(root->left,mpp)+helper(root->right,mpp);
        return mpp[root]=max(take,nottake);
    }
public:
    int rob(TreeNode* root) {
        map<TreeNode *,int> mpp;
        return helper(root,mpp);
    }
};