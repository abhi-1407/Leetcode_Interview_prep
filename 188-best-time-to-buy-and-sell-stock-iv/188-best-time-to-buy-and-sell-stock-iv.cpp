class Solution {
    int profitDP(vector<int> prices,int n,int count)
    {
        int dp[n+1][2][count+1];
        for(int i=0;i<n+1;i++)
            dp[i][0][0]=0;
        for(int i=0;i<n+1;i++)
            dp[i][1][0]=0;        
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<=count;j++)
            {
                dp[n][i][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=1;k<=count;k++)//as cap 0 has been computed
                {
                   if(j==1)
                   {
                    int pick=-prices[i]+dp[i+1][0][k];
                    int notpick=dp[i+1][1][k];
                    dp[i][j][k]=max(pick,notpick);
                   }
                   else
                   {
                    int pick=prices[i]+dp[i+1][1][k-1];
                    int notpick=dp[i+1][0][k];
                    dp[i][j][k]=max(pick,notpick);
                   }                     
                }                
            }
        }
        return dp[0][1][count];
    }
//     int profitDP(vector<int> prices,int n)
//     {
//         int dp[n+1][2];
//         dp[n][0]=0;
//         dp[n][1]=0;
//         for(int i=n-1;i>=0;i--)
//         {
//          for(int j=0;j<=1;j++)
//             {
//              int profit=0;
//             if(j==1)
//             {
//             int pick=-prices[i]+dp[i+1][0];               
//             int notpick=dp[i+1][1];
//             profit=max(pick,notpick);
//             }
//            else
//            {
//             int pick=prices[i]+dp[i+1][1];
//             int notpick=dp[i+1][0];
//             profit=max(pick,notpick);
//             } 
//              dp[i][j]=profit;
//             }
            
//         }
//     int profitDPSp(vector<int> prices,int n)
//     {
//         vector<int> ahead(2,0),curr(2,0);
//         ahead[0]=0;
//         ahead[1]=0;
//         for(int i=n-1;i>=0;i--)
//         {
//          for(int j=0;j<=1;j++)
//             {
//             int profit=0;
//             if(j==1)
//             {
//             int pick=-prices[i]+ahead[0];               
//             int notpick=ahead[1];
//             profit=max(pick,notpick);
//             }
//            else
//            {
//             int pick=prices[i]+ahead[1];
//             int notpick=ahead[0];
//             profit=max(pick,notpick);
//             } 
//              curr[j]=profit;
//             }
//             ahead=curr;
            
//         }
//      return ahead[1];   
//     }

public:
    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
      return profitDP(prices,n,k);  
    }
};