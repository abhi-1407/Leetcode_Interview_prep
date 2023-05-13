class Solution {
    int mod=pow(10,9)+7;
    long long helper(int len,int one,int zero,vector<long long> &dp)
    {
        if(len<0)
            return 0;
        if(len==0)
            return 1;
        if(dp[len]!=-1)
            return dp[len];
        long long sum=(helper(len-one,one,zero,dp)+helper(len-zero,one,zero,dp))%(mod);
        return dp[len]=sum;
            
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        long long count=0;
        vector<long long>dp(high+1,-1);
        for(long long i=low;i<=high;i++)
        {
            count=(count%mod+helper(i,one,zero,dp)%mod)%mod;
        }
        return count;
    }
};