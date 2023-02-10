class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>> visited(row,vector<int>(col,0));
        vector<vector<int>> distance(row,vector<int>(col,0));
        queue<pair<int,int>> q;
        int maxi=INT_MIN;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int x=it.first,y=it.second;
            int dr[]={1,0,-1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int newx=x+dr[i],newy=y+dc[i];
                if(newx<0 || newy<0 || newx>=grid.size() || newy>=grid[0].size())
                {
                    continue;
                }
                else if(!visited[newx][newy])
                {
                    distance[newx][newy]=distance[x][y]+1;
                    visited[newx][newy]=true;
                    q.push({newx,newy});
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                maxi=max(distance[i][j],maxi);
            }
        }
        
        return (maxi==0|| maxi==INT_MIN)?-1:maxi;
        
        
    }
};