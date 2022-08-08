class Solution {
    
    bool helper(int i,int j,int index,string word,vector<vector<char>>& board)
    {
        if(index==word.length())
        {
            return true;
        }
        
        else if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[index])
        {
            return false;
        }
       bool ans;
       char ch=board[i][j];
       board[i][j]='#';
       ans=helper(i+1,j,index+1,word,board) || helper(i,j+1,index+1,word,board)|| helper(i,j-1,index+1,word,board) || helper(i-1,j,index+1,word,board);
       board[i][j]=ch;           
       return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if((board[i][j]==word[0])&&(helper(i,j,0,word,board)))
                {
                    return true; 
                }                  
                               
            }
        }
        return false;
    }
};