class Solution {
    void dfs(vector<int> adj[],int element,vector<bool> &visited)
    {
        visited[element]=true;
        for(auto it:adj[element])
        {
            if(!visited[it])
            {
                dfs(adj,it,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<int> adj[n];
       int count=0;
       vector<bool> visited(n,0);
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i!=j and isConnected[i][j])
               {
                   adj[i].push_back(j);
                   adj[j].push_back(i);
               }
           }
       }
       for(int i=0;i<n;i++)
       {
           if(!visited[i])
           {
               count++;
               dfs(adj,i,visited);
           }
       }
       return count;        
    }
};