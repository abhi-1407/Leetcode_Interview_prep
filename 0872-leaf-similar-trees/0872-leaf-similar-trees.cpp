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
    void leaf(vector<int> &ans,TreeNode *root)
    {
        if(!(root->left) && !(root->right))
        {
            ans.push_back(root->val);
            return;
        }
        else
        {
            if(root->left)
            leaf(ans,root->left);
        
        if(root->right)
            leaf(ans,root->right);
            
        }
        
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1,ans2;
        leaf(ans1,root1);
        leaf(ans2,root2);
        if(ans1.size()!=ans2.size())
            return false;
        for(int i=0;i<ans1.size();i++)
        {
            if(ans1[i]!=ans2[i])
                return false;
        }
        return true;
    }
};