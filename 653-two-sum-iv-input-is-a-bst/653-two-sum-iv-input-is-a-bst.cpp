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
    private:
    void inorder(TreeNode *root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool TwoSum(vector<int> temp,int k)
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<temp.size();i++)
        {
            mpp[temp[i]]=i;
        }
        for(int i=0;i<temp.size();i++)
        {
            int ele=k-temp[i];
            if(mpp.find(ele)!=mpp.end() and mpp[ele]!=i)
                return true;
        }
        return false;
    }
public:
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int i=0,j=ans.size()-1;
        // while(i<j)
        // {
        //     int sum=ans[i]+ans[j];
        //     if(sum==k)
        //         return true;
        //     else if(sum>k)
        //     {
        //         j--;
        //     }
        //     else
        //     i++;
        // }
        // return false;
        return TwoSum(ans,k);
        
    }
};