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
           auto temp=q.front();
           q.pop();
           int x=temp.first;
           int y=temp.second;
           for(int i=0;i<8;i++)
           {
               int newx=x+dr[i];
               int newy=y+dc[i];
               if(newx<0 || newy<0 || newx>=n || newy>=m || grid[newx][newy]==1)
                   continue;
               if(distance[x][y]+1 < distance[newx][newy])
               {
                   distance[newx][newy]=1+distance[x][y];
                   q.push({newx,newy});
               }
               
           }            
        }
        return (distance[n-1][m-1]==1e9)?-1:distance[n-1][m-1];
    }
};