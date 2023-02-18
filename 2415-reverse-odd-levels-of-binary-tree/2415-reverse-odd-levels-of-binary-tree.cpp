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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        vector<int> temp;
        while(!q.empty())
        {
            int size=q.size();//write this here as size keeps changing
            vector<int> temp2;
            for(int i=0;i<size;i++)
            {
                auto it=q.front();
                q.pop();
                if(lvl%2)
                {
                    it->val=temp[size-i-1];
                }
                if(it->left)
                {
                    q.push(it->left);
                    temp2.push_back(it->left->val);
                }
                if(it->right)
                {
                    q.push(it->right);
                    temp2.push_back(it->right->val);
                }
            }
            temp=temp2;
            lvl++;
        }
        return root;
    }
};