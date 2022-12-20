class Disjoint{
    vector<int> size,parent;
    public:
    Disjoint(int n)
    {
        size.resize(n,1),parent.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findPar(int u)
    {
        if(parent[u]==u)
            return u;
        return parent[u]=findPar(parent[u]);
    }
    void UnionBySize(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)
            return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else if(size[ulp_u]>size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Disjoint ds(n);
        for(auto it:edges)
        {
            ds.UnionBySize(it[0],it[1]);
        }
        int a=ds.findPar(source);
        int b=ds.findPar(destination);
        return a==b;
        
    }
};