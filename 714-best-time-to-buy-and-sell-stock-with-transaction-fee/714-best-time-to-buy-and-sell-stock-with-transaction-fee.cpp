class Solution {
    int helperDP(vector<int> prices,int n,int fee)
    {
        int dp[n+1][2];
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
         for(int j=0;j<=1;j++)
            {
             int profit=0;
            if(j==1)
            {
            int pick=-prices[i]+dp[i+1][0];               
            int notpick=dp[i+1][1];
            profit=max(pick,notpick);
            }
           else
           {
            int pick=prices[i]+dp[i+1][1]-fee;
            int notpick=dp[i+1][0];
            profit=max(pick,notpick);
            } 
             dp[i][j]=profit;
            }
            
        }
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        return helperDP(prices,n,fee);
    }
};