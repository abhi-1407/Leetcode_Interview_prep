class Solution {
private:
    int n, m;
    int dp[70][70][70];
    int solve(vector<vector<int>>& grid, int r, int c1, int c2) {
        // base case
        if(r >= n)
            return 0;
        // memoization case
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        // calling recursion
        int ret = 0;
        if(c1 == c2)
            ret += grid[r][c1];
        else
            ret += grid[r][c1] + grid[r][c2];
        int mx = 0;
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(c1 + i < 0 or c1 + i >= m or c2 + j < 0 or c2 + j >= m)
                    continue;
                mx = max(mx, solve(grid, r + 1, c1 + i, c2 + j));
            }
        }
        return dp[r][c1][c2] = ret + mx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // using 3d dp as row will be same for both robots
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, m - 1);
    }
};