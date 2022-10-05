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
    void helper(TreeNode* root,int height,int val,int depth)
    {
        if(height+1==depth)
        {
            TreeNode *node1=new TreeNode(val);
            TreeNode *node2=new TreeNode(val);
            node1->left=root->left;
            node2->right=root->right;
            root->left=node1;
            root->right=node2;
            return;
        }
        if(root->left)
        helper(root->left,height+1,val,depth);
        if(root->right)
        helper(root->right,height+1,val,depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *node=new TreeNode(val);
            node->left=root;
            return node;
        }
        int height=1;
        helper(root,height,val,depth);
        return root;
    }
};