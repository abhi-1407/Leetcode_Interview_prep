class Solution {
    double helper(int n,int k,int row,int col,vector<vector<vector<double>>> &dp)
    {
        if(row<0 || col<0 || row>=n || col>=n)
        {
            return 0;
        }
        if(k==0)
        {
            return 1;
        }
        if(dp[row][col][k]!=-1)
            return dp[row][col][k];
        int dr[8]={2,2,-2,-2,1,1,-1,-1};
        int dc[8]={1,-1,1,-1,2,-2,2,-2};
        double ans=0;
        for(int i=0;i<8;i++)
        {
            int newdr=row+dr[i];
            int newdc=col+dc[i];
            ans+=helper(n,k-1,newdr,newdc,dp)/(8.0);
        }
        return dp[row][col][(double)k]=ans;
        
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(26, vector<vector<double>>(26, vector<double>(101, -1)));
        return helper(n,k,row,column,dp);
    }
};
