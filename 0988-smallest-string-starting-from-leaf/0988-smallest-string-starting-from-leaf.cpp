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
    void helper(TreeNode *root,string temp,string &ans)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            temp=char(root->val+'a')+temp;
            if(ans>temp || ans=="")
                ans=temp;
            return;
        }
        temp=char(root->val+'a')+temp;
        helper(root->left,temp,ans);
        helper(root->right,temp,ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans="",temp="";
        helper(root,temp,ans);
        return ans;
        
    }
};