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
    void helper(TreeNode *root,unordered_map<int,int> &ans)
    {
        if(!root)
            return;
        ans[root->val]++;
        helper(root->left,ans);
        helper(root->right,ans);
}
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> ans;
        vector<int> fans;
        int count=0;
        helper(root,ans);
        for(auto it:ans)
        {
            count=max(count,it.second);
        }
        for(auto it:ans)
        {
            if(it.second==count)
            {
                fans.push_back(it.first);
            }
        }
        return fans;
    }
};