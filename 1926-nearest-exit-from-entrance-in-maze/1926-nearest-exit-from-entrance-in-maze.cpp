class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       queue<pair<int,int>> q;
       q.push({entrance[0],entrance[1]});
       maze[entrance[0]][entrance[1]]='+';
       int steps=1;
       while(!q.empty())
       {
           int size=q.size();
           for(int i=0;i<size;i++)
           {
               int x=q.front().first;
               int y=q.front().second;
               q.pop();
               int dr[]={1,0,-1,0};
               int dc[]={0,1,0,-1};
               for(int d=0;d<4;d++)
               {
                   int newx=dr[d]+x;
                   int newy=dc[d]+y;
                   if(newx<0 || newy<0 || newx>=maze.size() || newy>=maze[0].size() || maze[newx][newy]=='+')//if its out of bound or blocked then continue
                       continue;
                   else if(newx==0 || newx==maze.size()-1 || newy==0 || newy==maze[0].size()-1)
                       return steps;
                   else
                   {
                       q.push({newx,newy});
                       maze[newx][newy]='+';
                   }
               }
           }
           steps++;//after exploring all paths then we'll increment the no of steps
       }
       return -1;
    }
};