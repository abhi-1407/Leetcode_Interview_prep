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
private:
    bool isBst(TreeNode *root,long long min,long long max)
{
    if(root==NULL)
        return true;
    if(root->val <= min || root->val >= max)
    {
        return false;
    }
    return isBst(root->left,min,root->val) && isBst(root->right,root->val,max) ;
}
    // bool isBST(TreeNode *root,long long int min,long long int max)
    // {
    //     if(root==NULL)
    //         return true;
    //     if(root->val> min && root->val<max)
    //     {
    //          bool left=isBST(root->left,min,root->val);
    //          bool right=isBST(root->right,root->val,max);
    //          return left && right;
    //     }
    //     else
    //     return false;
    // }
public:
    bool isValidBST(TreeNode* root) {
        
        long long minV = -30000000000;
        long long maxV = 30000000000;
        return isBst(root,minV,maxV);
        
    }
};