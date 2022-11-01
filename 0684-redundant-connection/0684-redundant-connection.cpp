vector<int> ans;
class Disjoint{
    public:
    vector<long long> rank,parent;
    Disjoint(int n)
    {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }    
    int findParent(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent[node]);
    }
/* redundant edge exists and hence we'll have to remove it,and since we need to remove the last redundant edge so we'll keep overwriting the value in ans */  
    void unionfind(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v)
        {
            ans={u+1,v+1};
            return;
        }
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]+=rank[ulp_v];
        }
        else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]+=ulp_v;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]+=ulp_v;
        }
    }
    
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Disjoint ds(n);
        for(auto it:edges)
        {
            int u=it[0]-1;
            int v=it[1]-1;
            ds.unionfind(u,v);
        }
        return ans;

    }
};