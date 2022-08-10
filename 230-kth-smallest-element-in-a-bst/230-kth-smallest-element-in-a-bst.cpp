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
    void solve(TreeNode* root,int &k,int &ans)
    {
        if(!root)
            return ;
        solve(root->left,k,ans);
        k--;
        if(!k)
        {
            ans=root->val;
        }
        solve(root->right,k,ans);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int ans;
        solve(root,k,ans);
        return ans;
    }
};