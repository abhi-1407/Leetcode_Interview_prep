class Solution {
    bool dfs(vector<int> &color,int node,vector<int> adj[],int c)
    {
        color[node]=c;
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(color,it,adj,!c)==false)
                    return false;
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(color,i,adj,0)==false)
                    return false;                    
            }
        }
        return true;
    }
};