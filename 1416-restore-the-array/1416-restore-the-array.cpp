class Solution {
    long long mod=pow(10,9)+7;
    
    int helper(string &s,long long idx,long long k,vector<long long>&dp)
    {
        if(idx>=s.length())
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        long long ans=0,sum=0,ways=0;
        for(long long i=idx;i<s.length();i++)
        {
            sum=(sum*10)+(s[i]-'0');
            if(sum>=1 && sum<=k)
            {
                ways=((ways%mod)+(helper(s,i+1,k,dp)%mod))%mod;
            }
            else
                break;
        }
        return dp[idx]=ways;
    }
public:
    int numberOfArrays(string s, int k) {
        vector<long long> dp(100001,-1);
     return helper(s,0,k,dp);   
    }
};