class Solution {
    bool dfs(vector<vector<int>> &ans,int dest,int node,vector<bool> &visited)
    {
        visited[node]=true;
        if(dest==node)
            return true;
        for(auto it:ans[node])
        {
            if(!visited[it])
            {
                if(dfs(ans,dest,it,visited))
                    return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
         vector<vector<int>> ans(n);
         if(source==destination)
             return true;
         for(auto it:edges)
         {
             int a=it[0];
             int b=it[1];
             ans[a].push_back(b);
             ans[b].push_back(a);
         }
        vector<bool> visited(n,false);
        for(auto it:ans[source])
        {
            if(dfs(ans,destination,it,visited))
                return true;
        }
        return false;
            
    }
};