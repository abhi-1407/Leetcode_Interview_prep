class Solution{
bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,vector<int>&delRow,vector<int>&delCol)
    {
       if((i<0 || i>=grid.size() || j<0 || j>=grid[0].size()))
           return 0;
       vis[i][j]=1;
       if(grid[i][j]==1) 
           return 1;    
       grid[i][j]=1;
       bool res=true;
       for(int indx=0;indx<4;indx++)
       {
           int newRow=i+delRow[indx];
           int newCol=j+delCol[indx];
           res=res&(dfs(newRow,newCol,grid,vis,delRow,delCol)); 
       }
       return res;
    }
    
    public:
    int closedIsland(vector<vector<int>>& grid) {

        vector<int>delRow={0,0,1,-1};
        vector<int>delCol={1,-1,0,0};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && vis[i][j]==0)
                {
                  if(dfs(i,j,grid,vis,delRow,delCol))
                    count++;
                }
            }
        }
        return count;

        
    }
};