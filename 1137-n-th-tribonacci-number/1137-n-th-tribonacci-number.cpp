class Solution {
public:
    int tribonacci(int n) 
    {
        // if(n==0)
        //     return 0;
        // if(n==1)
        //     return 1;
        // if(n==2)
        //     return 1;
        // return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++)
        {
            if(i==0)
                dp[i]=0;
            else if(i==1)
                dp[i]=1;
            else if(i==2)
                dp[i]=1;
            else
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};