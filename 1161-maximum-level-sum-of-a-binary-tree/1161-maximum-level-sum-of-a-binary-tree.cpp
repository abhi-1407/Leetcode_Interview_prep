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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        pair<int,int> ans;
        ans={INT_MIN,1};
        int lvl=1;
        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                auto it=q.front();
                sum+=it->val;
                q.pop();
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
            }
            if(sum>ans.first)
            {
                ans={sum,lvl};
            }  
            lvl++;
        }
        return ans.second;
        
    }
};