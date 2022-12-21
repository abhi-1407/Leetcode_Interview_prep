class Solution {
    bool helper(vector<int> adj[],int node,int c,vector<int> &group)
    {
        group[node]=c;
        int opp=!c;
        for(auto it:adj[node])
        {
            if(group[it]==-1)
            {
                if(!helper(adj,it,opp,group))
                    return false;
            }
            else
            {
                if(group[it]==group[node])
                    return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1],group(n+1,-1);
        for(auto it:dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<n+1;i++)
        {
            if(group[i]==-1)
            {
                if(!helper(adj,i,0,group))
                    return false;
            }
        }
        return true;
    }
};