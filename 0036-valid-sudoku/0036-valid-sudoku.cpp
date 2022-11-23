class Solution {
    bool isValid(int i,int j,vector<vector<char>> &board)
    {
        int row=i,col=j;
        char ch=board[row][col];
        for(int i=0;i<board.size();i++)
        {
            if(board[i][col]==ch and i!=row)
                return false;
        }
        for(int i=0;i<board[0].size();i++)
        {
            if(board[row][i]==ch and i!=col)
                return false;
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++)
        {
            for(int j=sc;j<sc+3;j++)
            {
                if(board[i][j]==ch and i!=row and j!=col)
                    return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.' and !isValid(i,j,board))
                {
                    return false;
                }
            }
        }
        return true;
    }
};