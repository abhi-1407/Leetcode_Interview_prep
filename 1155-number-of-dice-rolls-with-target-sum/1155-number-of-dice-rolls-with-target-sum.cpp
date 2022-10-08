class Solution {
    int mod=pow(10,9)+7;
//     int HelperMemo(int target,int k,int index,vector<vector<int>> &dp)
//     {
//         if(index==0)
//         {
//             if(target==0)
//             return 1;
//             else
//             return 0;
//         }
//         if(dp[target][index]!=-1)
//             return dp[target][index];
//         int count=0;
//         for(int i=1;i<=k;i++)
//         {
//             if(target>=i)
//             count=((count%mod)+HelperMemo(target-i,k,index-1,dp))%mod;
//         }
//         return dp[target][index]=(count%mod);
        
//     }
    
    int helperTab(int n,int k,int t)
    {
        vector<vector<int>> dp(t+1,vector<int>(n+1,-1));
        for(int target=0;target<t+1;target++)
        {
            for(int index=0;index<n+1;index++)
            {
                if(index==0)
                {
                    if(target==0)
                        dp[target][index]=1;
                    else
                        dp[target][index]=0;
                }
                else
                {
                    int count=0;
                    for(int m=1;m<=k;m++)
                    {
                        if(target>=m)
                           count=((count%mod)+dp[target-m][index-1])%mod;
                    }
                    dp[target][index]=(count%mod);
                }
            }
        }
        return dp[t][n];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        //vector<vector<int>> dp(target+1,vector<int>(n+1,-1));
        return helperTab(n,k,target);
        //return HelperMemo(target,k,n,dp);
    }
};