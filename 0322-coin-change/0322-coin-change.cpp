class Solution {
    int helper(int index,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(amount==0)
            return 0;
        if(index<0)
            return 1e5;
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int pick=1e5;
        if(coins[index]<=amount)
        {
            pick=1+helper(index,coins,amount-coins[index],dp);
        }
        int notpick=helper(index-1,coins,amount,dp);
        return dp[index][amount]=min(pick,notpick);
        
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins.size()-1,coins,amount,dp);
        return ans==1e5?-1:ans;
    }
};