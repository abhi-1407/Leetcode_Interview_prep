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
    if(root->val <= min || root->val >= max)//if the root's value is not in the range
    {
        return false;
    }
    /* if we are reaching till this point then it is in the range so check for left and 
    right trees */
    return isBst(root->left,min,root->val) && isBst(root->right,root->val,max) ;
   }
    
public:
    bool isValidBST(TreeNode* root) {
        
        long long minV = -30000000000;//as values can be very large
        long long maxV = 30000000000;//as values can be very large
        return isBst(root,minV,maxV);
        
    }
};