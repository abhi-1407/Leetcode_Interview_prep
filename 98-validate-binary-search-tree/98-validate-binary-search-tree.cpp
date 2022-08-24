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
bool helper(TreeNode *root,long long min,long long max)
{
    if(!root)
       return true;
    if(root->val > min and root->val < max)
    {
        int l=helper(root->left,min,root->val);
        int r=helper(root->right,root->val,max);
        return l&&r;
    }        
    return false;        
    
    
 }
public:
    bool isValidBST(TreeNode* root) {
        long long  l=LONG_MIN;
        long long r=LONG_MAX;
        return helper(root,l,r);
        
        
    }
};