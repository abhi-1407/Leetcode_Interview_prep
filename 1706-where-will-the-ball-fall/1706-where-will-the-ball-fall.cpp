class Solution {
    int dfs(vector<vector<int>>& grid,int i,int j,int n)
    {
        if(i>=n)
            return j;
        if(grid[i][j]==1 && j+1<=grid[i].size()-1 && grid[i][j+1]==1)
        {
            return dfs(grid,i+1,j+1,n);
        }
        if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1)
        {
            return dfs(grid,i+1,j-1,n);
        }
        return -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid[0].size();//no of balls
        int nrow=grid.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back(dfs(grid,0,i,nrow));
        }
        return ans;
    }
};