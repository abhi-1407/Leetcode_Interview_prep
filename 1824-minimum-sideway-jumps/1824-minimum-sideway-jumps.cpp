class Solution {
    int helper(vector<int>& obstacles,int i,int j,int &n,vector<vector<int>> &dp)
    {
        if(i==n-1) 
            return 0;
        if(obstacles[i]-1==j)
            return 1e8;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(obstacles[i+1]-1!=j)
            return helper(obstacles,i+1,j,n,dp);
        int ans=1e8;
        for(int k=0;k<3;k++)
        {
            if(obstacles[i]-1!=k)
            ans=min(ans,1+helper(obstacles,i+1,k,n,dp));
        }
        return dp[i][j]=ans;
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return helper(obstacles,0,1,n,dp);
    }
};