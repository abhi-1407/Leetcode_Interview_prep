class Solution {
    void helper(vector<int> adj[],vector<int> &visited,vector<int> &informTime,int node,int time,int &maxtime)
    {
        time+=informTime[node];
        if(adj[node].size()==0)
        {
            visited[node]=true;
            maxtime=max(time,maxtime);
        }
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=true;
                helper(adj,visited,informTime,it,time,maxtime);
            }
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        int maxtime=0;
        vector<int> visited(n,0);
        helper(adj,visited,informTime,headID,0,maxtime);
        return maxtime;
    }
};