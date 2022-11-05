class Solution {
    int helper(int floorsleft,int eggs,vector<vector<int>> &dp)
    {
        if(floorsleft<=1)
            return floorsleft;
/* if we have only 1 egg left then we have to use go from below to all the upper floors */
        if(eggs==1)
        {
            return floorsleft;
        }
        if(dp[floorsleft][eggs]!=-1)
            return dp[floorsleft][eggs];
        int mini=1e9;
        for(int i=1;i<floorsleft;i++)
        {
            int breaks=helper(i-1,eggs-1,dp);
            int doesntbreak=helper(floorsleft-i,eggs,dp);
            mini=min(mini,max(breaks,doesntbreak)+1);           
        }
        return dp[floorsleft][eggs]=mini;   
    }
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return helper(n,2,dp);
    }
};