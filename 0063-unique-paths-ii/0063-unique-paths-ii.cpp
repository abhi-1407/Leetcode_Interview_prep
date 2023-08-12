class Solution {
    int helper(int i,int j,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp)
    {
        if(i==0 && j==0 && obstacleGrid[i][j]!=1)
            return 1;
        if(i==0 || j==0|| (i<obstacleGrid.size() && j<obstacleGrid[0].size() && obstacleGrid[i][j]==1))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=helper(i-1,j,obstacleGrid,dp);
        int left=helper(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;  
    }
    
    int helperDP(int n,int m,vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0 && obstacleGrid[i][j]!=1)
                    dp[i][j]=1;
                else
                {
                    if(obstacleGrid[i][j]==1)
                        dp[i][j]=0;
                    else
                    {
                        int up=0,left=0;
                        if(i-1>=0)
                            up=dp[i-1][j];
                        if(j-1>=0)
                            left=dp[i][j-1];
                        dp[i][j]=up+left;
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
           int n=obstacleGrid.size(),m=obstacleGrid[0].size();
           //vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
           return helperDP(n,m,obstacleGrid);
    }
};