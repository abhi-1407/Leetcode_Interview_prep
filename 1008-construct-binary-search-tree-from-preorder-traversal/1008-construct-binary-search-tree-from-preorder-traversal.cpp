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
    TreeNode *helper(vector<int>& preorder,int mini,int maxi,int &index)
    {
        if(index>=preorder.size())//if the index has crossed the preorder
            return NULL;
        /*if the value of the node lies in the range then make the link*/
        if(preorder[index]> mini and preorder[index]<maxi)
        {
            TreeNode *temp=new TreeNode(preorder[index++]);
            temp->left=helper(preorder,mini,temp->val,index);
            temp->right=helper(preorder,temp->val,maxi,index);
            return temp;//return the pointer while coming back
        }
        else
            return NULL;//else there is no node over here so return a null
        
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return helper(preorder,0,1001,index);
        
    }
};