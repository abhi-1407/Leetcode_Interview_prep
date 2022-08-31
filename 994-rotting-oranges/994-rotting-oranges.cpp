class Solution {
    bool check(int i,int j,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1)
            return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int n=q.size();
            bool flag=false;//to see if we have oranges to rot or not
            while(n--)
            {
            auto ele=q.front();
            q.pop();
            
            int i=ele.first;
            int j=ele.second;
            if(check(i,j-1,grid) && grid[i][j-1]==1)
            {
                flag=true;
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            if(check(i,j+1,grid) && grid[i][j+1]==1)
            {
                flag=true;
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            if(check(i-1,j,grid) && grid[i-1][j]==1)
            {
                flag=true;
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(check(i+1,j,grid) && grid[i+1][j]==1)
            {
                flag=true;
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
               
            } 
            if(flag)//if we did rot some oranges then increment the counter
                count++;
    
            
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};