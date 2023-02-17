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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *node=root;
        vector<int> ans;
        while(true)
        {
            if(node)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty()==true)
                    break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
            
        }
        int mind=INT_MAX;
        for(int i=0;i<ans.size()-1;i++)
        {
            int d=abs(ans[i]-ans[i+1]);
            mind=min(mind,d);
        }
        return mind;
        
    }
};