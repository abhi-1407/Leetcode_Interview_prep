class Solution {
    bool dfs(vector<int> &path,vector<int>&visited,int node,vector<int> adj[],vector<int> &count)
    {
        visited[node]=1;
        path[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
               if(dfs(path,visited,it,adj,count))
                   return true;
            }
            else if(path[it])
            {
                return true;
            }
        }
        count[node]=1;
        path[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> path(n,0);
        vector<int> count(n,0);
        vector<int> ans;
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(path,visited,i,adj,count);
            }
        }
        for(int i=0;i<count.size();i++)
        {
            if(count[i]==1)
                ans.push_back(i);                
        }
        return ans;
    }
};