/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
void mapping(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &mpp)
{
    if(!root || root->left==NULL && root->right==NULL)
        return;
    if(root->left)
        mpp[root->left]=root;
    if(root->right)
        mpp[root->right]=root;
    mapping(root->left,mpp);
    mapping(root->right,mpp);
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode*> mpp;
        vector<int> ans;
        mapping(root,mpp);
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        unordered_map<TreeNode *,bool> visited;
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto it=q.front();
                q.pop();
                int lvl=it.second;
                if(it.second==k)
                {
                    ans.push_back(it.first->val);
                    continue;
                }
                if(it.first->left && !visited[it.first->left])
                {
                    q.push({it.first->left,lvl+1});
                    visited[it.first->left]=true;
                }
                if(it.first->right && !visited[it.first->right])
                {
                    q.push({it.first->right,lvl+1});
                    visited[it.first->right]=true;
                }
                if(mpp[it.first] && !visited[mpp[it.first]])
                {
                    q.push({mpp[it.first],lvl+1});
                    visited[mpp[it.first]]=true;
                }
            }
        }
        return ans;
        
    }
};