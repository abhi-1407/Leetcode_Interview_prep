class Solution {
    void dfs(int i,int j,vector<vector<int>> &grid,int &temp)
    {
        grid[i][j]=0;
        temp++;
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        for(int m=0;m<4;m++)
        {
            int ddr=i+dr[m];
            int ddc=j+dc[m];
            if(!(ddr<0 || ddc<0 || ddr>=grid.size() || ddc>=grid[0].size() || grid[ddr][ddc]==0))
            {
                dfs(ddr,ddc,grid,temp);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=0;
                    dfs(i,j,grid,temp);
                    maxi=max(temp,maxi);
                }
            }
        }
        return maxi;
    }
};