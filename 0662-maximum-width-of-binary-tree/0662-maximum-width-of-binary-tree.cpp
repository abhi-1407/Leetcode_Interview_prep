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
        queue<pair<TreeNode *,ll>> q;
        int maxi=0;
        q.push({root,0});
        while(!q.empty())
        {
            ll off=q.front().second;
            int size=q.size();
            int l=0,r=0;
            for(int i=0;i<size;i++)
            {
                auto it=q.front();
                q.pop();
                TreeNode *n=it.first;
                ll pos=it.second;
                if(i==0)
                {
                    l=pos-off;
                }
                if(i==size-1)
                {
                    r=pos-off;
                }
                if(n->left)
                {
                    q.push({n->left,2*(pos-off)+1});
                }
                if(n->right)
                {
                    q.push({n->right,2*(pos-off)+2});
                }
            }
            maxi=max(maxi,(int)r-l+1);
        }
        return maxi;
    }
};