class Solution {
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i > grid.size()-1 || j>grid[0].size()-1 || grid[i][j]==0)
            return ;
        grid[i][j]=0;
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
    }
        
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && (i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1))
                {
                    dfs(i,j,grid);
                }
            }
        }                  
                   
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }                 
        return count;
    } 
};