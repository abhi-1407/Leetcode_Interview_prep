class Solution {
public:
    void helper(TreeNode* root, int& maxDepth, int& leftVal, int depth) {
        if (root == NULL) {
            return;
        }
        
        helper(root->left, maxDepth, leftVal, depth+1);
        helper(root->right, maxDepth, leftVal, depth+1);
        
        if (depth > maxDepth) {
            maxDepth = depth;
            leftVal = root->val;
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int leftVal = root->val;
        helper(root, maxDepth, leftVal, 0);
        return leftVal;
    }
};