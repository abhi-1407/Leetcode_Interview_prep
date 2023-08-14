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
    pair<int,pair<int,int>> helper(TreeNode *root,int &maxi)
    {
        if(!root)
            return {0,{INT_MAX,INT_MIN}};
        auto l=helper(root->left,maxi);
        auto r=helper(root->right,maxi);
        pair<int,pair<int,int>> p;
        if(root->val>l.second.second && root->val<r.second.first)
        {
            maxi=max(maxi,root->val+l.first+r.first);
            p.first=root->val+l.first+r.first;
            p.second.first=min(root->val,l.second.first);
            p.second.second=max(root->val,r.second.second);
            return p;
        }
        return {0,{INT_MIN,INT_MAX}};
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};