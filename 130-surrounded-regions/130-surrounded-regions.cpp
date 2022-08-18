class Solution {
    bool isValid(int i,int j,vector<vector<char>>& board)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) 
        {
            return false;
        }
        return true;
    }
    void helper(int i,int j,vector<vector<char>>& board)
    {
        if(isValid(i+1,j,board) and board[i+1][j]=='O')
        {
            board[i+1][j]='C';
            helper(i+1,j,board);
        }
        if(isValid(i-1,j,board) and board[i-1][j]=='O')
        {
            board[i-1][j]='C';
            helper(i-1,j,board);
        }
        if(isValid(i,j+1,board) and board[i][j+1]=='O')
        {
            board[i][j+1]='C';
            helper(i,j+1,board);
        }
        if(isValid(i,j-1,board) and board[i][j-1]=='O')
        {
            board[i][j-1]='C';
            helper(i,j-1,board);
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O' and (i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1))
                {
                    board[i][j]='C';
                    helper(i,j,board);
                }
            }
        }
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='C')
                {
                    board[i][j]='O';
                }
                
            }
        }
        
        
        
    }
};