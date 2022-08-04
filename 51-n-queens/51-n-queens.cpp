class Solution {
    bool isSafe(int i,int j,vector<string> board,int n)
    {
        int row=i,col=j;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row=i,col=j;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        
        row=i,col=j;
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        return true;
        
    }
    void helper(int col,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board,n))
            {
                board[i][col]='Q';
                helper(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board;
    string s(n,'.');
    for(int i=0;i<n;i++)
    board.push_back(s);
    helper(0,board,ans,n);
    return ans;
    }
};