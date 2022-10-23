class Disjoint{
  public:
  vector<int> parent,rank,size;
  Disjoint(int n)
  {
      rank.resize(n+1,0);
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<n+1;i++)
      {
          parent[i]=i;
          size[i]=1;
      }
  }
  int findPar(int element)
  {
      if(parent[element]==element)
          return element;
      return parent[element]=findPar(parent[element]);
  }
  void UnionBySize(int u,int v)
  {
      int ulp_u=findPar(u);
      int ulp_v=findPar(v);
      if(ulp_u==ulp_v)
          return;
      if(ulp_u < ulp_v)
      {
          parent[ulp_u]=ulp_v;
          size[ulp_v]+=size[ulp_u];
      }
      else if(ulp_u > ulp_v)
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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0,maxcol=0;
        int n=stones.size();
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        Disjoint ds(maxrow+maxcol+1);
        unordered_map<int,int> nodes;
        for(auto it:stones)
        {
            int row=it[0];
            int col=it[1]+maxrow+1;
            ds.UnionBySize(row,col);
            nodes[row]=1;
            nodes[col]=1;
        }
        int count=0;
        for(auto it:nodes)
        {
            if(ds.findPar(it.first)==it.first)
                count++;
        }
        return n-count;
        
    }
};