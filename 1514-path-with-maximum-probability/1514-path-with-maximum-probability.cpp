class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> visited(n,0);
        priority_queue<pair<double,int>> pq;
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        visited[start]=0.0000;
        pq.push({1.0000,start});
        while(!pq.empty())
        {
            double cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                double adjCost=it.second;
                int adjNode=it.first;
                if(adjCost*cost > visited[adjNode])
                {
                    visited[adjNode]=adjCost*cost;
                    pq.push({adjCost*cost,adjNode});
                }
            }
        }
        return visited[end]==-1e9?0:visited[end];
    }
};