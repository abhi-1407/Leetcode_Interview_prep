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
        if(!root)//trivial case
            return;
        if(root->left==NULL and root->right==NULL)//leaf node
        {
            temp.push_back(root->val);//push the current node
            int sum=0;
            for(auto it:temp)//check the sum
            {
                sum+=it;
            }
            if(sum==targetSum)//if its equal to the targetSum then push this vector and return
            {
                ans.push_back(temp);
                return;
            }
            
        }
        /* no need to pop as we are passing by value */
        temp.push_back(root->val);//push the current node's value into the vector
        helper(root->left,temp,ans,targetSum);//call on the left node
        helper(root->right,temp,ans,targetSum);
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
       vector<int> temp;
       helper(root,temp,ans,targetSum);
       return ans;
    }
};