class Solution {
    void helper(vector<vector<int>>& grid,int i,int j)
    {
        if(i>grid.size()-1 || j>grid[0].size()-1 || i<0 || j<0 || grid[i][j]==1)
            return;
        grid[i][j]=1;        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        for(int m=0;m<4;m++)
        {
            int newx=dr[m]+i;
            int newy=dc[m]+j;
            helper(grid,newx,newy);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),-1));
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0 && (i==0 || j==0 ||i==grid.size()-1 || j==grid[0].size()-1))
                {
                     helper(grid,i,j);
                }
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {
                     (helper(grid,i,j));
                        count++;
                }
            }
        }
        return count;
    }
};