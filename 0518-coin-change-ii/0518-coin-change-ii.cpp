class Solution {
    int helper(int index,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(amount==0)
            return 1;
        if(index==0)
        {
            if(amount%coins[index]==0)
                return 1;
            else
                return 0;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick=0;
        if(coins[index]<=amount)
        {
            pick=helper(index,coins,amount-coins[index],dp);
        }
        int notpick=helper(index-1,coins,amount,dp);
        return dp[index][amount]=pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return helper(coins.size()-1,coins,amount,dp);
    }
};