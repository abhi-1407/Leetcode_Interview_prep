class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==0 and grid.size()==1 and grid[0].size()==1)
            return 1;
        if(grid[0][0]==1)
            return -1;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        distance[0][0]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        int dr[]={-1,0,1,0,-1,-1,1,1};
        int dc[]={0,1,0,-1,-1,1,-1,1};
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int dist=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            for(int i=0;i<8;i++)
            {
                int newx=dr[i]+x;
                int newy=dc[i]+y;
                if(newx<0 || newy<0 || newx>=n || newy>=m)
                    continue;
                else
                {
                    if((distance[newx][newy] > dist+1) and grid[newx][newy]==0)
                    {
                        if(newx==n-1 && newy==m-1)
                            return 1+dist;
                        distance[newx][newy]=dist+1;
                        q.push({dist+1,{newx,newy}});
                    }
                }
            }            
        }
        
        return -1;    
        
    }
};