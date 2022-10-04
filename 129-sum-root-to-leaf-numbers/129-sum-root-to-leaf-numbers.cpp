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
//     void helper(TreeNode *root,string s,vector<string> &ans)
//     {
//         if(!root)
//         {
//             return;
//         }
//         /* add the strings from root to leaf path */
//         if(root->left==NULL and root->right==NULL)
//         {
//             s+=to_string(root->val);
//             ans.push_back(s);
//         }
//         /* add the current value */
//         s+=to_string(root->val);
//         helper(root->left,s,ans);
//         helper(root->right,s,ans);
        
//     }
public:
    // int sumNumbers(TreeNode* root) {
    //     vector<string> ans;
    //     string s="";
    //     helper(root,s,ans);
    //     int sum=0;
    //     for(auto it:ans)
    //     {
    //         sum+=stoi(it);   
    //     }
    //     return sum;
    // }
    void helper(TreeNode *root,long long sum,long long &ans)
    {
        if(!root)
            return;
        if(root->left==NULL and root->right==NULL)
        {
            sum=sum*10+root->val;
            ans+=sum;
        }
        sum=sum*10+root->val;
        helper(root->left,sum,ans);
        helper(root->right,sum,ans);
    }
    int sumNumbers(TreeNode *root)
    {
        long long sum=0,ans=0;
        helper(root,sum,ans);
        return ans;
    }
};