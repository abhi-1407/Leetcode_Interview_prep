class Solution {
    int helper(vector<vector<int>>& triangle,int row,int col,vector<vector<int>> &dp)
    {
        if(row==triangle.size())
        {
            return 0;
        }
        if(col<0 || col>=triangle[row].size())
            return 1e5;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int down=triangle[row][col]+helper(triangle,row+1,col,dp);
        int right=triangle[row][col]+helper(triangle,row+1,col+1,dp);
        return dp[row][col]=min({down,right});
        
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(triangle,0,0,dp);
        
    }
};