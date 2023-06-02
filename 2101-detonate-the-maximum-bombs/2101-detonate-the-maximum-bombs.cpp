#define ll long long 
class Solution {
    void dfs(int node,vector<int> adj[],int &count,vector<int> &visited)
    {
        count++;
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,count,visited);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        //sort(bombs.begin(),bombs.end());
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<bombs.size();i++)
        {
            ll s1=bombs[i][0];
            ll e1=bombs[i][1];
            ll r1=bombs[i][2];
            for(int j=0;j<bombs.size();j++)
            {
                if(i!=j)
                {
                    ll s2=bombs[j][0];
                    ll e2=bombs[j][1];
                    ll r2=bombs[j][2];
                    if((abs(s2-s1)*abs(s2-s1)+abs(e2-e1)*abs(e2-e1))<=(r1*r1))
                    {
                        adj[i].push_back(j);
                    }
                }
                
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            vector<int> visited(n,0);
            dfs(i,adj,count,visited);
            maxi=max(maxi,count);
        }
        return maxi;
    }
};