//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // pq.push({0,S});
        // vector<int> distance(V,INT_MAX);
        // distance[S]=0;
        // while(!pq.empty())
        // {
        //     int dist=pq.top().first;
        //     int node=pq.top().second;
        //     pq.pop();
        //     for(auto it: adj[node])
        //     {
        //         int adjdist=it[1];
        //         int adjnode=it[0];
        //         if(adjdist + dist < distance[adjnode])
        //         {
        //             distance[adjnode]=dist+adjdist;
        //             pq.push({distance[adjnode],adjnode});
        //         }
        //     }
        // }
        // return distance;
        set<pair<int,int>> s;
        s.insert({0,S});
        vector<int> distance(V,INT_MAX);
        distance[S]=0;
        while(!s.empty())
        {
            auto i=*(s.begin());//pull out the first node
            int dist=i.first;
            int node=i.second;
            s.erase(s.begin());//remove this from the set
            for(auto it: adj[node])
            {
                int adjdist=it[1];
                int adjnode=it[0];
                if(adjdist + dist < distance[adjnode])
                {
                    if(s.find({adjdist,adjnode})!=s.end())
                    {
                        s.erase({adjdist,adjnode});
                    }
                    distance[adjnode]=dist+adjdist;
                    s.insert({distance[adjnode],adjnode});
                }
            }
        }
        return distance;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends