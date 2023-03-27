class Solution {
    int helper(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1)
            return 1e9;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=helper(grid,i,j+1,dp);
        int down=helper(grid,i+1,j,dp);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(grid,0,0,dp);
    }
};