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
    void h(int level,TreeNode *root,map<int,int> &mpp)
    {
        if(root==NULL)
            return;
      
        h(level+1,root->right,mpp);
        h(level+1,root->left,mpp);
        if(mpp.find(level)==mpp.end())
        {
            mpp[level]=root->val;
        } 
        
    }
public:
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int> mpp;
        h(0,root,mpp);
        for(auto it:mpp)
            ans.push_back(it.second);
        return ans;      
        
    }
};