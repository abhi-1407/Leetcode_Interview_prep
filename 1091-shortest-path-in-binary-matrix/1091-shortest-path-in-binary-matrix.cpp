class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        queue<pair<int,int>> q;
        int dr[]={1,0,-1,0,-1,1,-1,1};
        int dc[]={0,1,0,-1,1,-1,-1,1};
        if(grid[0][0]==0)
        {
            distance[0][0]=1;
            q.push({0,0});
        }
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            for(int i=0;i<8;i++)
            {
                int xx=x+dr[i];
                int yy=y+dc[i];
                if(xx<0 || yy<0 || xx>n-1 || yy>n-1 || grid[xx][yy]!=0)
                    continue;
                if(distance[xx][yy]>1+distance[x][y])
                {
                    distance[xx][yy]=1+distance[x][y];
                    q.push({xx,yy});
                }
            }
        }
        return distance[n-1][n-1]==1e9 ? -1 : distance[n-1][n-1];
    }
};