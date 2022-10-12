//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(vector<int> adj[],int node,vector<int> &visited,vector<int> &path)
    {
        visited[node]=1;
        path[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]==-1)
            {
               if(dfs(adj,it,visited,path))
               {
                   return true;
               }
            }
            else if(path[it]==1)
            return true;
        }
        path[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> path(V,0);
        vector<int> visited(V,-1);
        for(int i=0;i<V;i++)
        {
            if(visited[i]==-1)
            {
              if(dfs(adj,i,visited,path))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends