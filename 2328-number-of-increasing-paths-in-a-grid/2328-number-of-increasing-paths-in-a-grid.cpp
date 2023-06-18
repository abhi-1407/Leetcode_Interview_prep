class Solution {
    int mod=pow(10,9)+7;
    int dfs(vector<vector<int>> &dp,int i,int j,vector<vector<int>>& grid)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        int sum=1;
        for(int k=0;k<4;k++)
        {
            int newx=i+dr[k];
            int newy=j+dc[k];
            if(newx<0 || newy<0 || newx>=grid.size() || newy>=grid[0].size() || grid[newx][newy]<=grid[i][j])
                continue;
            sum=(sum%mod+dfs(dp,newx,newy,grid)%mod)%mod;
        }
        return dp[i][j]=sum%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int count=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                count=(count%mod+dfs(dp,i,j,grid)%mod)%mod;
            }
        }
        return count;
    }
};