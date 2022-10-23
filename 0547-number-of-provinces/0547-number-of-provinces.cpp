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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        Disjoint ds(n);
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    ds.unionByRank(i,j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ds.findPar(i)==i)
                count++;
        }
        return count;
        
        
    }
};