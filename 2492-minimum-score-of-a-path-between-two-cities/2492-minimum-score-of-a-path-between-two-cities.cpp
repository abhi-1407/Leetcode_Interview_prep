class Solution {
    void helper(vector<vector<pair<int,int>>> &adj,int &mini,int node,vector<int> &visited,int n)
    {
        visited[node]=true;
        for(auto it:adj[node])
        {
            mini=min(mini,it.second);
            if(!visited[it.first])
            {   
                helper(adj,mini,it.first,visited,n);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> visited(n+1,false);
        int mini=INT_MAX;
        helper(adj,mini,1,visited,n);
        return mini;
    }
};