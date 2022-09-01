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
    
    void helper(TreeNode *root,int &count,int maxi)
    {
        if(root==NULL)
        {
            return;
        }
/* if we encounter a number greater than or equal to the current max then we'll update our count and also increase maxi if its greater */
        if(root->val >= maxi) 
        {
            count++;
            maxi=max(maxi,root->val);
        }
        helper(root->left,count,maxi);
        helper(root->right,count,maxi);
    }
    
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        helper(root,count,INT_MIN);
        return count;
    }
};