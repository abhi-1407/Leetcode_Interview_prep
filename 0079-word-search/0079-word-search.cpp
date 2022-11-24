class Solution {
    bool dfs(vector<vector<char>> &board,int i,int j,int index,string word)
    {
        if(index==word.size()-1)
        {
            return true;
        }
        char ch=board[i][j];
        board[i][j]='#';
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        for(int m=0;m<4;m++)
        {
            int newx=i+dr[m];
            int newy=j+dc[m];
            if(newx<0 || newy<0 || newx>=board.size() || newy>=board[0].size() || board[newx][newy]!=word[index+1])
                continue;
            if(board[newx][newy]==word[index+1])
            {
                if(dfs(board,newx,newy,index+1,word))
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
                if(board[i][j]==word[0] and dfs(board,i,j,0,word))
                {
                    return true;
                }
            }

        }
        return false;
        
    }
};