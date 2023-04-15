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
    void dfs(TreeNode *root,unordered_map<int,int> &mpp,int lvl,int sum)
    {
        if(root==NULL)
            return;
        int temp=(root->left?root->left->val:0)+(root->right?root->right->val:0);
        root->val=mpp[lvl]-sum;
        if(root->left)
        dfs(root->left,mpp,lvl+1,temp);
        if(root->right)
        dfs(root->right,mpp,lvl+1,temp);
        
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int,int> mpp;
        queue<TreeNode *> q;
        q.push(root);
        int lvl=0;
        mpp[lvl]=root->val;
        lvl++;
        while(!q.empty())
        {
            int s=q.size();
            int sum=0;
            while(s--)
            {
                auto it=q.front();
                q.pop();
                if(it->left)
                {
                    sum+=it->left->val;
                    q.push(it->left);
                }
                if(it->right)
                {
                    sum+=it->right->val;
                    q.push(it->right);
                }
            }
            mpp[lvl]=sum;
            lvl++;
        }
        dfs(root,mpp,0,root->val);
        return root;
    }
};