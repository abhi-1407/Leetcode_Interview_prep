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
string constructTree(TreeNode* root){
        if(root == NULL) return "";
        string s =to_string(root->val);
        if(root->left) {
            s+= '(' + constructTree(root->left) + ')';
        } 
        if(!root->left && root->right) s+="()";
        if(root->right) {
            s+= '(' + constructTree(root->right) + ')';
        }
        return s;
    }
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        return constructTree(root);
    }
};