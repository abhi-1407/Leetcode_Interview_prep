class Solution {
public:
//      int count(int i,int j,int m,int n,vector<vector<int>> &dp)
//     {
//         if(i>m-1 || j>n-1)
//             return 0;
//         if(i==m-1 && j==n-1)
//             return 1;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         else
//             return dp[i][j]=count(i+1,j,m,n,dp)+count(i,j+1,m,n,dp);
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return count(0,0,m,n,dp);        
        
//     }
//     int uniquePaths(int m,int n)
//     {
//         int dp[m][n];
//         dp[0][0]=1;;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {                
//                 if(i==0 && j==0)continue;
//                 int left=0,up=0;
//                 if(i>0)
//                 up=dp[i-1][j];
//                 if(j>0)
//                 left=dp[i][j-1];
//                 dp[i][j]=left+up;
                
                
//             }
//         }
//         return dp[m-1][n-1];
//     }
    
        int uniquePaths(int m,int n)
    {
        int dp[m][n];
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {    
                if(i==m-1 && j==n-1)
                    dp[i][j]=1;
                else
                {
                int right=0,left=0;
                if(i+1<m)
                    right=dp[i+1][j];
                if(j+1<n)
                    left=dp[i][j+1];
                dp[i][j]=right+left;
                    
                }
                
            }
        }
        return dp[0][0];
    }
};