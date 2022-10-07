class Solution {
    int helper(int n,vector<int> &dp) {
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int one=helper(n-1,dp);
        int two=helper(n-2,dp);
        return dp[n]=one+two;
        
    }
public:
    int climbStairs(int n) {
        vector<int> dp(46,-1);
        return helper(n,dp);
        
    }
};