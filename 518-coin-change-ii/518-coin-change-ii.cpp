class Solution {
//     int counter(int amount,vector<int> coins,int index,vector<vector<int>> &dp)
//     {
//         if(index==0)
//         {
//             return (amount%coins[index]==0);
//         }
//         if(dp[index][amount]!=-1)
//             return dp[index][amount];
//         int pick=0;
//         if(coins[index]<=amount)
//         {
//             pick=counter(amount-coins[index],coins,index,dp);
//         }
//         int notpick=counter(amount,coins,index-1,dp);
//         return dp[index][amount]=pick+notpick;
//     }
    
    int HelperTab(int a,vector<int> &coins)
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(a+1,0));
        for(int index=0;index<n;index++)
        {
            for(int amount=0;amount<=a;amount++)
            {
                if(index==0)
                {
                    dp[index][amount]=(amount%coins[index]==0);
                }
                else
                {
                    int pick=0;
                    if(coins[index]<=amount)
                        pick=dp[index][amount-coins[index]];
                    int notpick=dp[index-1][amount];
                    dp[index][amount]=pick+notpick;
                }
            }
        }
        return dp[n-1][a];       
        
    }
public:
    int change(int amount, vector<int>& coins) {
        return HelperTab(amount,coins);
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        // return counter(amount,coins,coins.size()-1,dp);        
    }
};