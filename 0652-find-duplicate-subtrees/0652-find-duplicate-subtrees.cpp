class Solution {
    unordered_map<string,int> mpp;
    string helper(TreeNode *root,vector<TreeNode*> &vec)
    {
        if(!root)
            return "N";//delimiter to distinguish between 1N2N3NN and 123NN 
        string ans="";              
        ans+=to_string(root->val)+","+helper(root->left,vec)+","+helper(root->right,vec);        
        if(mpp[ans]==1)
        {
            vec.push_back(root);
        }
        mpp[ans]++;
        return ans;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> vec;
        helper(root,vec);
        return vec;
    }
};