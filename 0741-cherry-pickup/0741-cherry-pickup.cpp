class Solution {
//     int helper(int r1,int r2,int c1,vector<vector<int>> &grid)
//     {
//         int n=grid.size();
        
//         if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
//             return INT_MIN;
//         if(r1==n-1 && r2==n-1 && c1==n-1 && c2==n-1)
//             return 1;
//         int count=0;
//         if(r1==r2 && c1==c2)
//         {
//             count+=grid[r1][c1];
//         }
//         else
//         {
//             count+=grid[r1][c1]+grid[r2][c2];
//         }
//         int way1=helper(r1+1,r2+1,c1,c2,grid);
//         int way2=helper(r1,r2,c1+1,c2+1,grid);
//         int way3=helper(r1+1,r2,c1+1,c2,grid);
//         int way4=helper(r1,r2+1,c1,c2+1,grid);
//         count+=max({way1,way2,way3,way4});
//         return count;
//     }
        int helper(int r1,int r2,int c1,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
        {
            int n=grid.size();
            int c2=r1+c1-r2;
            if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
                return INT_MIN;
            if(r1==n-1 && r2==n-1 && c1==n-1 && c2==n-1)
                return grid[r1][c1];
            if(dp[r1][r2][c1]!=-1)
                return dp[r1][r2][c1];
            int count=0;
            if(r1==r2 && c1==c2)
            {
                count+=grid[r1][c1];
            }
            else
            {
                count+=grid[r1][c1]+grid[r2][c2];
            }
            int way1=helper(r1+1,r2+1,c1,grid,dp);
            int way2=helper(r1,r2,c1+1,grid,dp);
            int way3=helper(r1+1,r2,c1,grid,dp);
            int way4=helper(r1,r2+1,c1+1,grid,dp);
            count+=max({way1,way2,way3,way4});
            return dp[r1][r2][c1]=count;
        }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=helper(0,0,0,grid,dp);
        return ans<0?0:ans;
    }
};