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
    void helper(TreeNode *root,vector<int> temp,vector<vector<int>> &ans,int targetSum)
    {
        if(!root)
            return;
        if(root->left==NULL and root->right==NULL)
        {
            temp.push_back(root->val);
            int sum=0;
            for(auto it:temp)
            {
                sum+=it;
            }
            if(sum==targetSum)
            {
                ans.push_back(temp);
                return;
            }
            
        }
        temp.push_back(root->val);
        helper(root->left,temp,ans,targetSum);
        helper(root->right,temp,ans,targetSum);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
       vector<int> temp;
       helper(root,temp,ans,targetSum);
       return ans;
    }
};