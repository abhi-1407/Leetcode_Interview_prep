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
//     bool hasPathSum(TreeNode* root, int &targetSum) {
//         if(root==NULL)
//         {
//            return false;
//         }
//         if(root->left==NULL && root->right==NULL && targetSum-(root->val)==0)
//         {
//             return true;
//         }
        
//         targetSum-=root->val;
//         if(hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum))
//             return true;
//         targetSum+=root->val;
//         return false;
        
//     }
//     bool h(TreeNode* root, int targetSum,int sum) {
//         if(root==NULL)
//         {
//            return false;
//         }
//         if(root->left==NULL && root->right==NULL && sum+(root->val)==targetSum)
//         {
//             return true;
//         }
        
//         sum+=root->val;
//         if(h(root->left,targetSum,sum) || h(root->right,targetSum,sum))
//             return true;
//          return false;
        
//     }
//     bool hasPathSum(TreeNode *root,int &targetSum)
//     {
//         return h(root,targetSum,0);
//     }
       bool helper(TreeNode *root,int curr)
       {
           if(!root)//if we have crossed a leaf node
               return false;
           if(root->left==NULL and root->right==NULL)//if its a leaf node
           {
               if(curr-(root->val)==0)
               {
                   return true;
               }
               else
               {
                   return false;
               }
           }
           bool l=helper(root->left,curr-(root->val));//calling for the left side
           bool r=helper(root->right,curr-(root->val));//calling for the right side
           return l||r;
       }
       bool hasPathSum(TreeNode *root,int &targetSum)
       {
           return helper(root,targetSum);
       }
};