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
    void helper(TreeNode *root,int mini,int &second)
    {
        if(!root)
            return;
/* We want to find if the second is not visited or if there is a number smaller than second but larger than mini then that could be a solution */
        if(root->val > mini && (second==-1 || root->val < second))
        {
            second=root->val;
        }
        helper(root->left,mini,second);
        helper(root->right,mini,second);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
       int mini=root->val,second=-1;
       helper(root,mini,second);
       return second;
    }
};