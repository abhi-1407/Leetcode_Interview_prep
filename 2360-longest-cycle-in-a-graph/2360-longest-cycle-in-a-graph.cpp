class Solution {
    bool helper(int node,vector<int> &edges,vector<int> &visited,vector<int> &path,vector<int> &distance,int d,int &ans)
    {
        if(node!=-1)
        {
            if(!visited[node])
            {
                visited[node]=true;
                distance[node]=d;
                path[node]=true;
                helper(edges[node],edges,visited,path,distance,d+1,ans);
            }
            else if(path[node])
            {
                ans=max(ans,d-distance[node]);
            }
            path[node]=false;
        }
            return false;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> visited(n,0),path(n,0),distance(n,0);
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                helper(i,edges,visited,path,distance,0,ans);
        }
        return ans;
    }
};