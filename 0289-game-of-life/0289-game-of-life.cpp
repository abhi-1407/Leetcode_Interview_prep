class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans(board.size(),vector<int>(board[0].size(),0));
        int dr[]={0,0,-1,1,-1,1,1,-1};
        int dc[]={1,-1,0,0,1,1,-1,-1};
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==1)
                {
                    int count=0;
                    for(int m=0;m<8;m++)
                    {
                        int newx=i+dr[m];
                        int newy=j+dc[m];
                        if(newx>=board.size() || newy>=board[0].size() || newx<0 || newy<0)
                        continue;
                        if(board[newx][newy]==1)
                            count++;                    
                    }
                    if(count<2)
                    {
                        ans[i][j]=0;
                    }
                    else if(count==2 || count==3)
                    {
                        ans[i][j]=1;
                    }

                }
                else
                {
                    int count=0;
                    for(int m=0;m<8;m++)
                    {
                       int newx=i+dr[m];
                       int newy=j+dc[m];
                       if(newx>=board.size() || newy>=board[0].size() || newx<0 || newy<0)
                           continue;
                       if(board[newx][newy]==1)
                           count++;                    
                     }
                     if(count==3)
                     {
                        ans[i][j]=1;
                     }
                }
            }
        }            
        board=ans;        
    }
};