class Solution {
public:
        
    int dp[1001][1001];
    
    int minKeyPress(int step, int value, int copy, int&n)
    {
        if(step>n || value>n) return INT_MAX;
        
        if(value==n) return step;
        
        if(dp[step][value]!=-1) return dp[step][value];
        
        return dp[step][value] = min(minKeyPress(step+1,value+copy,copy,n),minKeyPress(step+2,2*value,value,n));
    }
    
    int minSteps(int n) {
    
        if(n==1) return 0;
        memset(dp,-1,sizeof(dp));
        return minKeyPress(1,1,1,n);
    }
};