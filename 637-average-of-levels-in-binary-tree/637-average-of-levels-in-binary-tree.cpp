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
    void helper(TreeNode *root,map<int,pair<double,int>> &mpp,int level)
    {
        if(!root)
            return;              
        helper(root->left,mpp,level+1);
        helper(root->right,mpp,level+1);
        
        mpp[level].first+=root->val;
        mpp[level].second+=1; 
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        map<int,pair<double,int>> mpp;
        helper(root,mpp,0);
        for(auto it:mpp)
        {
            auto i=it.second;
            int count=i.second;
            double sum=i.first;
            if(count==0)
            {
                ans.push_back(sum);
            }
            else
            {
                ans.push_back(sum/count);
            }
        }
        return ans;
    }
};