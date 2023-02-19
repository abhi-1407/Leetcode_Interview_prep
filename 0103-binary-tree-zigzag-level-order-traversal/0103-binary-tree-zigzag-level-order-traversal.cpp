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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode *>q;
        bool r=false;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto it=q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
            }
            if(r)
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            else
            {
                ans.push_back(temp);
            }
            r=!r;
        }
        return ans;
    }
};