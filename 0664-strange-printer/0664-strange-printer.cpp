class Solution {
    int helper(string &s,int i,int j,vector<vector<int>> &dp)
    {
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            mini=min(mini,helper(s,i,k,dp)+helper(s,k+1,j,dp));
        }
        return dp[i][j]=mini-(int)(s[i]==s[j]);
        
    }
public:
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(s,0,n-1,dp);
    }
};