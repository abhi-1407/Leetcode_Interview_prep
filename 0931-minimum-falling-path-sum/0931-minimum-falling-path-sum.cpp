class Solution {
    int helper(vector<vector<int>>& matrix,vector<vector<int>> &dp,int row,int col)
    {
        if(row==matrix.size())
            return 0;
        if(row<0 || col<0 || row>matrix.size()-1 || col>matrix.size()-1)
            return 1e9;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int left=matrix[row][col]+helper(matrix,dp,row+1,col-1);
        int right=matrix[row][col]+helper(matrix,dp,row+1,col);
        int below=matrix[row][col]+helper(matrix,dp,row+1,col+1);
        return dp[row][col]=min(left,min(right,below));        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),mini=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            mini=min(mini,helper(matrix,dp,0,i));
        }
        return mini;        
    }
};