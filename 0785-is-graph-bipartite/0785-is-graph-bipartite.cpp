class Solution {
    bool helper(vector<int> &color,vector<vector<int>> &graph,int i,vector<int> adj[])
    {
        queue<int> q;
        q.push(i);//push the starting node into the queue
        color[i]=0;//start with one color say 0
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int nodecolor=color[node];
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!nodecolor;//color it with the opp color
                    q.push(it);//push it in to the queue
                }
                else if(color[it]==nodecolor)//if adj nodes get the same color
                {
                    return false;
                } 
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> p;
        int n=graph.size();
        vector<int> color(n,-1);
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)//as it not a n*n matrix
            {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                if(helper(color,graph,i,adj)==false)
                    return false;
            }
        }
        return true;       
        
    }
};