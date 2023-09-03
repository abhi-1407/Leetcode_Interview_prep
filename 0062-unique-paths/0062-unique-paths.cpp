class Solution {
    int helper(int m,int n,vector<vector<int>> &dp)
    {
        if(n==0 && m==0)
            return 1;
        if(n<0 || m<0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int left=helper(m,n-1,dp);
        int top=helper(m-1,n,dp);
        return dp[m][n]=left+top;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};