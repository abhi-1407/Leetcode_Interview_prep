class Solution {
    void helper(vector<pair<int,int>> adj[],vector<bool> &visited,int node,int &count)
    {
        visited[node]=true;
        for(auto it:adj[node])
        {
            int n=it.first;
            int val=it.second;
            if(!visited[n])
            {
                count+=val;
                helper(adj,visited,n,count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adj[n];
        vector<bool> visited(n,false);
        int count=0;
        for(auto it:connections)
        {
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        helper(adj,visited,0,count);
        return count;
    }
};