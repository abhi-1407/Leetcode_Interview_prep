class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;     
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
//         for(int i=0;i<grid.size();i++)
//         {
//             for(int j=0;j<grid[0].size();j++)
//             {
//                 if(grid[i][j]==0)
//                     count++;
                
//             }
//         }
//         if(count==grid[0].size()*grid.size()) //edge case if you put count in the starting of the loop
//             return 0;
//         count=0;
        int dr[]={0,1,-1,0};
        int dc[]={1,0,0,-1};
        while(!q.empty())
        {
            
            int n=q.size();
            bool flag=false;
            for(int i=0;i<n;i++)
            { 
                auto it=q.front();
                q.pop();
                int row=it.first,col=it.second;
                for(int j=0;j<4;j++)
                {
                int newr=row+dr[j];
                int newc=col+dc[j];
                if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid[0].size())
                {
                    continue;
                }
                else
                {
                    if(grid[newr][newc]==1)
                    {
                        flag=true;
                        grid[newr][newc]=2;
                        q.push({newr,newc});                        
                    }
                }
                    
                }               
            }    
            
                if(flag)
                    count++; 
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return count;
                 
    }
};