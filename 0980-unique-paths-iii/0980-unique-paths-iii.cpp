class Solution {
    int helper(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &visited)
    {
        if(grid[i][j]==2)
        {
            visited[i][j]=1;
            for(int k=0;k<visited.size();k++)
            {
                for(int l=0;l<visited[0].size();l++)
                {
                    if(visited[k][l]==-1 && grid[k][l]!=-1)
                    {
                        visited[i][j]=-1;
                        return 0;
                    }
                }
            }   
            visited[i][j]=-1;   
            return 1;
        }
        visited[i][j]=1;
        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,1,-1};
        int ans=0;
        for(int m=0;m<4;m++)
        {
            int xx=i+dr[m];
            int yy=j+dc[m];
            if(xx<0 || yy<0 || xx>grid.size()-1 || yy>grid[0].size()-1 || grid[xx][yy]==-1 || grid[xx][yy]==1 || visited[xx][yy]!=-1)
            {
                continue;
            }
            else
            {
                ans+=helper(grid,xx,yy,visited);
            }
        }
        visited[i][j]=-1;
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return (helper(grid,i,j,visited));
                }
            }
        }
        return -1;
        
    }

};