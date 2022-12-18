//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    void dfs1(int node,vector<int> adj[],vector<bool> &visited,stack<int> &st)
    {
        visited[node]=true;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfs1(it,adj,visited,st);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node,vector<int> adj2[],vector<bool> &visited)
    {
        visited[node]=true;
        for(auto it:adj2[node])
        {
            if(!visited[it])
            {
                dfs2(it,adj2,visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool> visited(V,false);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            dfs1(i,adj,visited,st);
        }
        vector<int> adj2[V+1];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            for(auto it:adj[i])
            {
                adj2[it].push_back(i);
            }
        }
        int count=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!visited[node])
            {
                count++;
                dfs2(node,adj2,visited);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends