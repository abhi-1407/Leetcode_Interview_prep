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
    vector<int> merge(vector<int> &first,vector<int> &second)
    {
        int i=0,j=0;
        vector<int> ans;
        while(i<first.size() && j<second.size())
        {
            if(first[i]<=second[j])
            {
                ans.push_back(first[i]);
                i++;
            }
            else 
            {
                ans.push_back(second[j]);
                j++;
            }
        }
        while(i<first.size())
        {
            ans.push_back(first[i]);
            i++;
        }
        while(j<second.size())
        {
            ans.push_back(second[j]);
            j++;
        }
        return ans;
    }
    void helper(TreeNode *root,vector<int> &temp)
    {
        if(!root)
            return;
        helper(root->left,temp);
        temp.push_back(root->val);
        helper(root->right,temp);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> temp1,temp2;
        helper(root1,temp1);
        helper(root2,temp2);
        return merge(temp1,temp2);
    }
};