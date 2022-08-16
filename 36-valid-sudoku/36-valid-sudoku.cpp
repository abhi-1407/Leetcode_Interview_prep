class Solution {
    bool isValid(vector<vector<char>>& board,int row,int col)
    {
          char element=board[row][col];
          for(int i=0;i<9;i++)
          {
              if(i!=row && board[i][col]==element)
                  return false;
          }
           for(int i=0;i<9;i++)
          {
              if(i!=col && board[row][i]==element)
                  return false;
          }
          int startr=(row/3)*3;
          int startc=(col/3)*3;
          for(int i=startr;i<startr+3;i++)
          {
              for(int j=startc;j<startc+3;j++)
              {
                  if(board[i][j]==element && row!=i && col!=j)
                  {
                      return false;
                  }
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
                if(board[i][j]!='.' && !isValid(board,i,j))
                    return false;
            }
        }
        return true;
        
    }
};