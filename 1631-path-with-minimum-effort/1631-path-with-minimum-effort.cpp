class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        distance[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int diff=it.first;
            int x=it.second.first;
            int y=it.second.second;
            // x-1,y
            // x,y-1
            // x+1,y
            // x,y+1
            if(x==n-1 and y==m-1)
                return diff;
            if(x<0 || y<0 || x>=n || y>=m || heights[x][y]==0)
            {
                    continue;
            }
            for(int i=0;i<4;i++)
            {
                int newx=x+dr[i];
                int newy=y+dc[i];                
                if(newx <= n-1 && newy <= m-1 && newx >=0 && newy>=0)
                {
                    int neweff=max(abs(heights[newx][newy]-heights[x][y]),diff);
                    if(neweff < distance[newx][newy])
                    {
                        distance[newx][newy]=neweff;
                        pq.push({neweff,{newx,newy}});
                    }
                }
            }
        }
        return 0;       
        
    }
};