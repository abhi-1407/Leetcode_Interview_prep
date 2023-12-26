class Solution {
    int mod=pow(10,9)+7;
    int helper(int n,int target,vector<vector<int>> &dp,int k)
    {
        if(n==0)
        {
            if(target==0)
                return 1;
            else
                return 0;
        }
        if(dp[n][target]!=-1)
            return dp[n][target];
        int count=0;
        for(int i=1;i<=k;i++)
        {
            if(target-i>=0)
            {
                count=(count+helper(n-1,target-i,dp,k))%mod;
            }
        }
        return dp[n][target]=count;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return helper(n,target,dp,k)%mod;
    }
};