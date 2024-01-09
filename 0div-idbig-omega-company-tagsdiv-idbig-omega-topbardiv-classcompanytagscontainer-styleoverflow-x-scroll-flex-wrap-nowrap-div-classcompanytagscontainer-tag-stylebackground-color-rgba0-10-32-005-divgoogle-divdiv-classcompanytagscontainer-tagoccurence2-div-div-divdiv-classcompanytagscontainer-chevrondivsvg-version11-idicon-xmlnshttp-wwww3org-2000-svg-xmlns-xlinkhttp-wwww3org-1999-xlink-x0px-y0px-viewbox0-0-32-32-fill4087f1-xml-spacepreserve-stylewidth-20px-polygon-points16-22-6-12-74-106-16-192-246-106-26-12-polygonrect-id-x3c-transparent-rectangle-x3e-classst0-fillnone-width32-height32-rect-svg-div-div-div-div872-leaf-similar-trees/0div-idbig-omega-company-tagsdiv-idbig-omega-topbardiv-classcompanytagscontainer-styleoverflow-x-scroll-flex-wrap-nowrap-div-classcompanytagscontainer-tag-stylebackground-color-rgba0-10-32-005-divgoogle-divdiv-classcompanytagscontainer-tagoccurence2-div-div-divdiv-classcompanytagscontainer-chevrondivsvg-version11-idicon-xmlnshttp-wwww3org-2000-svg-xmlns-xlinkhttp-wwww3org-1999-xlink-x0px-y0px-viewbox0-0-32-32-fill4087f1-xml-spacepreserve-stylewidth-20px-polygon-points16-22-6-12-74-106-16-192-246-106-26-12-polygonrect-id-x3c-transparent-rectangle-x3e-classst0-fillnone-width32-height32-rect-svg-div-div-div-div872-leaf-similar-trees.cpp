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
    
    void helper(TreeNode *root,string &ans)
    {
        if(!root)
            return ;
        helper(root->left,ans);
        if(root->left==NULL && root->right==NULL)
        {
            ans+=to_string(root->val)+"#";
        }
        helper(root->right,ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string ans1,ans2;
        helper(root1,ans1);
        helper(root2,ans2);
        return ans1==ans2;
    }
};