class Solution {
    bool helper(int i,int j,vector<vector<char>> &board, string word,int index)
    {
        if(index==word.size()-1)
        {
            return true;
        }
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        int ch=board[i][j];
        board[i][j]='#';
        for(int m=0;m<4;m++)
        {
            int newx=i+dr[m];
            int newy=j+dc[m];
            if(newx<0 || newy<0 || newx>=board.size() || newy>=board[0].size())
                continue;
            if(board[newx][newy]==word[index+1])
            {
               if(helper(newx,newy,board,word,index+1))
                   return true;
            }
        }
        board[i][j]=ch;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0]&& helper(i,j,board,word,0))
                    return true; 
            }
        }
        return false;
               
    }
};