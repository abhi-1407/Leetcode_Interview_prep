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
    void helper(TreeNode *root,pair<int,int> &ans,int data,int height)
    {
        if(!root)
        {
            return;
        }
        if((root->left && root->left->val==data) || (root->right && root->right->val==data))
        {
            ans.first=height;
            ans.second=root->val;//set the previous node as the parent
            return;
        }
        helper(root->left,ans,data,height+1);//go into the tree using dfs
        helper(root->right,ans,data,height+1);//go into the tree using dfs
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x||root->val==y)
        return false;
        pair<int,int> temp1={0,-1},temp2={0,-1};
        helper(root,temp1,x,0);
        helper(root,temp2,y,0);
        if(temp1.first==temp2.first && temp1.second!=temp2.second)
        {
            return true;
        }
        return false;
    }
};