class Solution {
    bool valid(vector<vector<char>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        return true;
    }
   void helper(vector<vector<char>> &grid,int i,int j)
   {
       grid[i][j]='0';
       if(valid(grid,i+1,j) and grid[i+1][j]=='1')
       {
           helper(grid,i+1,j);
       }
       if(valid(grid,i,j+1) and grid[i][j+1]=='1')
       {
           helper(grid,i,j+1);
       }
       if(valid(grid,i-1,j) and grid[i-1][j]=='1')
       {
           helper(grid,i-1,j);
       }
       if(valid(grid,i,j-1) and grid[i][j-1]=='1')
       {
           helper(grid,i,j-1);
       }
   }
   int dfs(int i,int j,vector<vector<char>> &grid)
   {
       int count=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[i].size();j++)
           {
               if(grid[i][j]=='1')
               {                  
                  helper(grid,i,j);
                  count++; 
               }             
               
           }
       }
       return count;
   }
public:
    int numIslands(vector<vector<char>>& grid) {
        return dfs(0,0,grid);
    }
};