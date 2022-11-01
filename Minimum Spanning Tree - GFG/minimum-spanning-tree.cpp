//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Disjoint{
public:
vector<int> parent,rank;
Disjoint(int nodes)
{
    rank.resize(nodes+1,0);
    parent.resize(nodes+1);
    for(int i=0;i<nodes+1;i++)
    parent[i]=i;
}

int findParent(int node)
{
    if(node==parent[node])
        return node;
    return parent[node]=findParent(parent[node]);    
}

void UnionBySize(int u,int v)
{
    int ul_u=findParent(u);
    int ul_v=findParent(v);
    if(ul_u==ul_v)return;
    if(rank[ul_u]<rank[ul_v])
    {
        parent[ul_u]=ul_v;
        rank[ul_v]+=rank[ul_u];

    }
    else if(rank[ul_u]>rank[ul_v])
    {
        parent[ul_v]=ul_u;
        rank[ul_u]+=rank[ul_v];
    }
    else
    {
        parent[ul_v]=ul_u;
        rank[ul_u]+=rank[ul_v];
    }
}
};

class Solution
{
	public:
	//function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> nodes;
        Disjoint ds(V-1);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int x=i;
                int y=adj[i][j][0];
                int w=adj[i][j][1];
                nodes.push_back({w,{x,y}});
            }
            
        }
        sort(nodes.begin(),nodes.end());
        int sum=0;
        for(auto it:nodes)
        {
            int x=it.second.first,y=it.second.second,w=it.first;
            if(ds.findParent(x)!=ds.findParent(y))
            {
                ds.UnionBySize(x,y);
                sum+=w;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends