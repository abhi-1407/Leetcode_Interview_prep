class Solution {
    int counter(int amount,vector<int> coins,int index,vector<vector<int>> &dp)
    {
        if(index==0)
        {
            return (amount%coins[index]==0);
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick=0;
        if(coins[index]<=amount)
        {
            pick=counter(amount-coins[index],coins,index,dp);
        }
        int notpick=counter(amount,coins,index-1,dp);
        return dp[index][amount]=pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return counter(amount,coins,coins.size()-1,dp);        
    }
};