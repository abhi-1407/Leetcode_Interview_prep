class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,-1));
        int dr[]={0,1,-1,0};
        int dc[]={-1,0,0,1};
        for(int i=0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
              if(mat[i][j]==0)
              {
                  visited[i][j]=1;
                  q.push({i,j});
              }
          }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newx=dr[i]+x;
                int newy=dc[i]+y;
                if(newx<0 || newy<0 || newx>=m || newy>=n)
                    continue;
                else if(mat[newx][newy]==1 and visited[newx][newy]==-1)
                {
                    mat[newx][newy]=mat[x][y]+1;
                    visited[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
        return mat;
        
    }
};