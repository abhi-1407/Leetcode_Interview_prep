class Solution {
    //using recursion
//     int helper(int index,vector<int>& prices,int buy,int n)
//     {
//         if(index >= n)
//             return 0;
//         if(buy)
//         {
//             int pick=-prices[index]+helper(index+1,prices,0,n);
//             int notpick=0+helper(index+1,prices,1,n);
//             return max(pick,notpick);
//         }
//         else
//         {
//             int pick=prices[index]+helper(index+2,prices,1,n);
//             int notpick=0+helper(index+1,prices,0,n);
//             return max(pick,notpick);
//         }
            
        
//     }
    
    int helperDP(vector<int>& prices , int n)
    {
        int dp[n+2][2];//n+2 as (n-1)+(i+2) = (n+i+1)  
        for(int i=0;i<n+2;i++)//base case of the recursion
        {
            dp[i][0]=0;
            dp[i][1]=0;
        }
        for(int i=n-1;i>=0;i--)
        {            
            for(int j=0;j<=1;j++)
            {              
                if(j)
                {
                  int pick=-prices[i]+dp[i+1][0];
                  int notpick=0+dp[i+1][1];
                  dp[i][j]=max(pick,notpick);
                }
                else
                {
                  int pick=prices[i]+dp[i+2][1];
                  int notpick=0+dp[i+1][0];
                  dp[i][j]=max(pick,notpick);
                }
            }
            
        }
        return dp[0][1];
            
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return helperDP(prices,n);
       // return helper(0,prices,1,n);
    }
};