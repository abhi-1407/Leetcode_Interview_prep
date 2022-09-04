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
    void helper(TreeNode *root,int level,int hd,map<int,vector<pair<int,int>>> &mpp)
    {
        if(!root)
            return;
        mpp[hd].push_back({level,root->val});
        helper(root->left,level+1,hd-1,mpp);
        helper(root->right,level+1,hd+1,mpp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mpp;
        helper(root,0,0,mpp);
        vector<vector<int>> ans;
        for(auto it: mpp)
        {
            vector<int> temp;            
            sort(begin(it.second),end(it.second));//sorting it level wise
            for(auto i:it.second)
            {
               temp.push_back(i.second);
            }
            ans.push_back(temp);           
        }
        return ans;        
    }
};