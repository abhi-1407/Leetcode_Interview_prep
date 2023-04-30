class DSU
{
    vector<int> parent,rank;
    public:
    DSU(int size)
    {
        parent.resize(size);
        rank.resize(size,0);
        for(int i=0;i<size;i++)
            parent[i]=i;
    }
    int find(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=find(parent[node]);
    }
    bool UnionBySize(int u,int v)
    {
        int a=find(u),b=find(v);
        if(a==b)
            return false;
        if(rank[a]<rank[b])
        {
            parent[a]=b;
        }
        else if(rank[a]>rank[b])
        {
            parent[b]=a;
        }
        else
        {
            parent[a]=b;
            rank[b]++;
        }
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU bob(n+1),alice(n+1);
        int b=0,a=0;
        int removed=0;
        for(auto it:edges)
        {
            if(it[0]==3)
            {
                if(alice.UnionBySize(it[1],it[2]))
                {
                    bob.UnionBySize(it[1],it[2]);
                    b++;
                    a++;
                }
                else
                    removed++;
            }
        }
        for(auto it:edges)
        {
            if(it[0]==1)
            {
                if(alice.UnionBySize(it[1],it[2]))
                    a++;
                else
                    removed++;
            }
            else if(it[0]==2)
            {
                if(bob.UnionBySize(it[1],it[2]))
                    b++;
                else
                    removed++;
            }
        }
        if((b==n-1 && a==n-1))
            return removed;
        else
            return -1;
        
    }
};