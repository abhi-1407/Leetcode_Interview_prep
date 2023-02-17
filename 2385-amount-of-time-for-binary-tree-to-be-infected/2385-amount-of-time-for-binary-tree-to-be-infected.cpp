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
    int bfs(unordered_map<int,vector<int>> &graph,int start)
    {
        queue<int> q;
        unordered_map<int,bool> visited;
        q.push(start);
        int count=-1;
        visited[start]=true;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int t=q.front();
                q.pop();
                for(auto it:graph[t])
                {
                    if(visited[it]!=true)
                    {
                        visited[it]=true;
                        q.push(it);
                    }
                }
                
            }
            count++;
        }
        return count;
    }
  
    void helper(TreeNode *root,unordered_map<int,vector<int>> &graph)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;
        if(root->left!=NULL)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            
            
        }
        if(root->right!=NULL)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            
        }
        helper(root->left,graph);
        helper(root->right,graph);
    }
    
public:
    int amountOfTime(TreeNode* root, int start) 
    {
        TreeNode *temp=root;
        unordered_map<int,vector<int>>graph;
        temp=root;
        helper(temp,graph);
        return bfs(graph,start);
    }
};