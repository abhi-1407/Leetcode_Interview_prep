class Solution {
    int mod=pow(10,9)+7;
    int helper(int target,int k,int index,vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        if(dp[target][index]!=-1)
            return dp[target][index];
        int count=0;
        for(int i=1;i<=k;i++)
        {
            if(target>=i)
            count=((count%mod)+helper(target-i,k,index-1,dp))%mod;
        }
        return dp[target][index]=(count%mod);
        
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target+1,vector<int>(n+1,-1));
        return helper(target,k,n,dp);
    }
};