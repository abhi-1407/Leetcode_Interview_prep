class Solution {
    void dfs(vector<long long> adj[],vector<bool> &visited,long long &counter,long long i)
    {
        visited[i]=true;
        counter++;
        for(auto it:adj[i])
        {
            if(!visited[it])
            dfs(adj,visited,counter,it);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long> adj[n];
        for(auto it:edges)
        {
            int s=it[0];
            int e=it[1];
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        long long res=0;
        vector<bool> visited(n,false);
        for(long long i=0;i<n;i++)
        {
            long long counter=0;
            if(!visited[i])
            {
                dfs(adj,visited,counter,i);
                res+=(counter*(counter-1))/2;
            }
        }
        res-=((long long)n*((long long)(n-1)))/2;
        return abs(res);
    }
};