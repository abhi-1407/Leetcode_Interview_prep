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

/* 
   If dir=0 ->left
      dir=1 ->right
*/
class Solution {
//     int helper(TreeNode *root,int dir)
//     {
//         if(root==NULL)
//             return 0;
        
//         if(root->left==NULL and root->right==NULL)
//             return 0;
//         if(dir==0 and root->right==NULL)
//             return 0;
//         if(dir==1 and root->left==NULL)
//             return 0;
//         int l=0,r=0;
//         if(dir==0)
//             r=helper(root->right,!dir);
        
//         if(dir==1)
//             l=helper(root->left,!dir);
//         return 1+max(l,r);
//     }
    
//     void helper2(TreeNode *root,int &maxi)
//     {
//         if(root==NULL)
//             return;
//         maxi=max({maxi,helper(root,0),helper(root,1)});
//         helper2(root->left,maxi);
//         helper2(root->right,maxi);
//     }
        int maxi=0;
        void helper(TreeNode *root,int dir,int currLen)
        {
            if(root==NULL)
                return ;
            maxi=max(maxi,currLen);
            helper(root->left,0,dir?currLen+1:1);
            helper(root->right,1,dir?1:currLen+1);
        }
public:
    int longestZigZag(TreeNode* root) {
        if(root==NULL)
            return 0;
         helper(root,1,0);
         helper(root,0,0);
        return maxi;
    }
};