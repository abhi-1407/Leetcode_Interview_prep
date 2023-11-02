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
    pair<int,int> helper(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return {0,0};
        auto l=helper(root->left,ans);
        auto r=helper(root->right,ans);
        int num=l.first+r.first+root->val;
        int count=l.second+r.second+1;
        if(root->val==(num/count))
        {
            ans++;
        }
        return {num,count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};