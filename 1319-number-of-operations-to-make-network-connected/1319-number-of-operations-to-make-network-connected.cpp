class Disjoint{
  public:
  vector<int> rank,parent;
  Disjoint(int temp)
  {
      int n=temp;
      rank.resize(n+1,0);
      parent.resize(n+1);  
      for(int i=0;i<n+1;i++)
      {
          parent[i]=i;
       }
  }
  
  int findPar(int node)
  {
      if(node==parent[node])
          return node;
      return parent[node]=findPar(parent[node]);
  }
  void unionByRank(int u,int v)
  {
      int ulp_u=findPar(u);
      int ulp_v=findPar(v);
      if(ulp_u==ulp_v)
          return;
      else if(rank[ulp_u]<rank[ulp_v])
          parent[ulp_u]=ulp_v;
      else if(rank[ulp_v]<rank[ulp_u])
          parent[ulp_v]=ulp_u;
      else //if they are same
      {
          parent[ulp_v]=ulp_u;
          rank[ulp_u]++;
      }      
  }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int extra=0,components=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)==ds.findPar(v))
            {
                extra++;
            }
            else
            {
                ds.unionByRank(u,v);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ds.findPar(i)==i)
                components++;
        }
        return components-1<=extra?components-1:-1;
    }
};