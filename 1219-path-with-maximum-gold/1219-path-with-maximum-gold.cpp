class Solution {
    int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>> &visited)
    {
        int ans=INT_MIN;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]==1)
            return 0;
        visited[i][j]=1;
        ans=grid[i][j]+max({helper(i+1,j,grid,visited),helper(i,j+1,grid,visited),helper(i-1,j,grid,visited),helper(i,j-1,grid,visited)});
        visited[i][j]=0;
        return ans;
            
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxi=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
                    maxi=max(helper(i,j,grid,visited),maxi);
                }
            }
        }
        return maxi;
    }
};