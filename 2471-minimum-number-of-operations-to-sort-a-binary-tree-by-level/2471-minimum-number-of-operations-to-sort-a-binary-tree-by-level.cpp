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
    int helper(vector<int>&y){
        int swaps = 0;
        vector<pair<int,int>>v;
        for(int i=0;i<y.size();i++){
            v.push_back({y[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            pair<int,int> p = v[i];
            int ele = p.first;
            int index = p.second;
            if(i!=index){
                swaps++;
                swap(v[i],v[index]);
                i--;
            }
        }
        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;
            for(int i=0;i<size;i++){
                auto it = q.front();
                ans.push_back(it->val);
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            count += helper(ans);
        }
        return count;
    }
};