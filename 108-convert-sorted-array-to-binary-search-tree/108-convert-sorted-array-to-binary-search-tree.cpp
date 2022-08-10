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
    TreeNode *makeTree(vector<int> nums,int start,int end)
    {
        if(start>end)return NULL; // base case
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);//make this as the node
        root->left=makeTree(nums,start,mid-1);//call for the left node
        root->right=makeTree(nums,mid+1,end);//call for the right node
        return root;//return the root at the end
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    return makeTree(nums,0,nums.size()-1);
    
    }
};