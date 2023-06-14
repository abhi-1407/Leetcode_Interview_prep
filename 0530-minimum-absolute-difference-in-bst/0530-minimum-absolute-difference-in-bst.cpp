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
    void helper(TreeNode *root,vector<int> &ans)
    {
        if(!root)
            return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        int temp=INT_MAX;
        for(int i=1;i<ans.size();i++)
        {
            temp=min(temp,abs(ans[i]-ans[i-1]));
        }
        return temp;
    }
};