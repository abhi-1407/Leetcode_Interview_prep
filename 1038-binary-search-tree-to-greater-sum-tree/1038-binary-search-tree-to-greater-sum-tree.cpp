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
        if(root==NULL)
            return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    
    void builder(TreeNode *root,vector<int> &prefix,map<int,int> mpp)
    {
        if(root==NULL)
            return;
        builder(root->left,prefix,mpp);
        root->val=mpp[root->val];
        builder(root->right,prefix,mpp);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        vector<int> ans,prefix;
        helper(root,ans);
        prefix.resize(ans.size());
        prefix[ans.size()-1]=ans[ans.size()-1];
        for(int i=ans.size()-2;i>=0;i--)
            prefix[i]=prefix[i+1]+ans[i];
        map<int,int> mpp;
        for(int i=0; i<ans.size(); i++){
            mpp[ans[i]] = prefix[i];
        }
        builder(root,prefix,mpp);
        return root;
    }
};