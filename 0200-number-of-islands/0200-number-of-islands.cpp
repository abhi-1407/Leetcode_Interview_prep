class Solution {
    bool check(vector<vector<char>>& grid,int i,int j)//to check if the position does even exist
    {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        if(i<0 || j<0 || i>n || j>m)
            return false;
        else
            return true;
    }
    void helper(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='0';
        if(check(grid,i-1,j) and grid[i-1][j]=='1')//intitally the position should exist even and then check if its one then call for dfs
        {
            helper(grid,i-1,j);
        }
        if(check(grid,i,j-1) and grid[i][j-1]=='1')
        {
            helper(grid,i,j-1);
        }
        if(check(grid,i+1,j) and grid[i+1][j]=='1')
        {
            helper(grid,i+1,j);
        }
        if(check(grid,i,j+1) and grid[i][j+1]=='1')
        {
            helper(grid,i,j+1);
        }
        return;//if all the conditions are false then return
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1') //if there's a point that begins with 1
                {
                    helper(grid,i,j);//call helper which esentially is dfs
                    count++;//increment the counter for every operation, dfs will make the adjacent '1's and 0
                }
            }
        }
        return count;//return the count
    
    }
};