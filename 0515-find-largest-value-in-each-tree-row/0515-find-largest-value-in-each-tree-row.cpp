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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int max_num = INT_MIN;
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                max_num = max(max_num,it->val);
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            ans.push_back(max_num);
        }
        return ans;
    }
};