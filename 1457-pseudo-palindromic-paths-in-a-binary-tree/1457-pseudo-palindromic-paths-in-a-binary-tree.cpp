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
    unordered_map<int,int> mpp;
    void helper(TreeNode *root,int &ans)
    {
        if(!root)
            return;
        mpp[root->val]++;
        if(!root->left && !root->right)
        {
            int count=0;
            for(auto it:mpp)
            {
                if(it.second%2!=0)
                    count++;
                if(count>=2)
                    break;
            }
            if(count<=1)
                ans+=1;
        }
        helper(root->left,ans);
        helper(root->right,ans);
        mpp[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};