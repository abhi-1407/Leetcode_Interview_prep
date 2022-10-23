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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint ds(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                else
                {
                    int dr[]={1,0,-1,0};
                    int dc[]={0,1,0,-1};
                    for(int k=0;k<4;k++)
                    {
                        int newx=i+dr[k];
                        int newy=j+dc[k];
                        if(newx<0 || newy<0 || newx>=n || newy>=n || grid[newx][newy]==0)continue;
                        int nodeno=i*n+j;
                        int adjno=newx*n+newy;
                        ds.UnionBySize(nodeno,adjno);//making connection of all the node with adjacent nodes
                    }
                }
            }
        }
        int maxsize=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)continue;
                unordered_set<int> st;
                int dr[]={1,0,-1,0};
                int dc[]={0,1,0,-1};                    
                    for(int k=0;k<4;k++)
                    {
                        int newx=i+dr[k];
                        int newy=j+dc[k];
                        if(newx<0 || newy<0 || newx>=n || newy>=n || grid[newx][newy]==0)continue;
                        else
                        {
                            st.insert(ds.findPar(newx*n+newy));
                        }
                    }
                int tempsize=0;
                for(auto it:st)
                {
                    tempsize+=ds.size[it];
                }
                maxsize=max(maxsize,tempsize+1);// +1 for the zero that has been converted into 1                
            }
        }
        for(int i=0;i<n*n;i++)
        {
            maxsize=max(maxsize,ds.size[ds.findPar(i)]);
        }
        return maxsize;
        
    }
};