class Solution {
    int helper(int i,int j,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp)
    {
        if(i==0 && j==0 && obstacleGrid[i][j]!=1)
            return 1;
        if(i<0 || j<0|| (i<obstacleGrid.size() && j<obstacleGrid[0].size() && obstacleGrid[i][j]==1))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=helper(i-1,j,obstacleGrid,dp);
        int left=helper(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;  
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
           int n=obstacleGrid.size(),m=obstacleGrid[0].size();
           vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
           return helper(n-1,m-1,obstacleGrid,dp);
    }
};