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

#define ll long long
class Solution {

public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxi=INT_MIN;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            int m=q.front().second;
            int left,right;
            for(int i=0;i<n;i++)
            {
                ll index=q.front().second-m;
                TreeNode *t=q.front().first;
                q.pop();
                if(i==0)
                {
                    left=index;
                }
                if(i==n-1)
                {
                    right=index;
                }
                if(t->left)
                {
                    q.push({t->left,2*index});
                }
                if(t->right)
                {
                    q.push({t->right,2*index+1});
                }
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};