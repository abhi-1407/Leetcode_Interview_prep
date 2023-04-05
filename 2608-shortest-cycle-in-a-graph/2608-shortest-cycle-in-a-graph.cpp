/* A the edge weights are 1 , hence we can use simple bfs to increment the distance */
class Solution {
    void bfs(vector<set<int>> &adj,vector<int> &dist,int ele)
    {
        queue<int> q;
        dist[ele]=0;
        q.push(ele);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[it]==1e9)
                {
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
                else
                    continue;
            }
        }
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<set<int>> adj(n);
        int result=1e9;
        for(auto it:edges)
        {
            int a=it[0];
            int b=it[1];
            adj[a].insert(b);
            adj[b].insert(a);
        }
        for(auto it:edges)
        {
            int a=it[0];
            int b=it[1];
            adj[a].erase(b);
            adj[b].erase(a);
            vector<int> dist(n,1e9);
            bfs(adj,dist,a);
            result=min(result,dist[a]+dist[b]+1);
            
        }
        if(result==1e9)
            return -1;
        return result;
    }
};