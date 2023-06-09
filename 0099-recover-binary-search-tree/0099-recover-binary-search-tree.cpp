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
    TreeNode *first=NULL,*prev=NULL,*middle=NULL,*last=NULL;
    void helper(TreeNode *root)
    {
        if(root==NULL)
            return ;
        helper(root->left);
        if(prev!=NULL && (prev->val > root->val))
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
        helper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        if(first and last)
        {
            swap(first->val,last->val);
        }
        else if(first && middle)
        {
            swap(first->val,middle->val);
        }
    }
};