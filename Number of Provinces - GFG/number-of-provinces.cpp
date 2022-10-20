//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void helper(vector<int> &visited,int node,vector<int> adj[])
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                helper(visited,it,adj);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> visited(V,0);
        int count=0;
        vector<int> a[V];
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(i!=j and adj[i][j]==1)
                {
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                count++;
                helper(visited,i,a);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends